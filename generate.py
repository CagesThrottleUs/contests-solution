#!/usr/bin/env python3
"""Generate standalone solution file for Codeforces submission."""

import sys
import os
from pathlib import Path


def read_file(filepath: str) -> str:
    """Read file contents."""
    with open(filepath, 'r') as f:
        return f.read()


def extract_problem_code(problem_content: str) -> str:
    """Extract only the implementation from problem file."""
    lines = problem_content.split('\n')
    result: list[str] = []
    skip_block_comment = False

    for line in lines:
        # Skip problem comment and includes already in template
        if line.startswith('// Problem:'):
            continue
        # Skip copyright/license block comment (/* ... */)
        stripped = line.strip()
        if stripped.startswith('/*'):
            skip_block_comment = True
        if skip_block_comment:
            if '*/' in line:
                skip_block_comment = False
            continue
        result.append(line)

    return '\n'.join(result).strip()


def generate_solution(template_content: str, problem_code: str) -> str:
    """Combine template and problem code, removing LOCAL blocks."""
    lines = template_content.split('\n')
    result: list[str] = []
    skip_local = False
    skip_problem_include = False
    
    for line in lines:
        # Handle LOCAL blocks
        if '#ifdef LOCAL' in line:
            skip_local = True
            continue
        if skip_local and '#endif' in line:
            skip_local = False
            continue
        if skip_local:
            continue
            
        # Handle PROBLEM_FILE include section
        if '#ifdef PROBLEM_FILE' in line:
            skip_problem_include = True
            # Insert problem code here instead
            result.append('\n' + problem_code)
            continue
        if skip_problem_include and '#endif' in line:
            skip_problem_include = False
            continue
        if skip_problem_include:
            continue
            
        result.append(line)
    
    return '\n'.join(result)


def main() -> None:
    """Main entry point."""
    if len(sys.argv) != 2:
        print("Usage: python3 generate.py <problem_file.cpp>")
        print("Example: python3 generate.py 1903A.cpp")
        sys.exit(1)
    
    problem_file = sys.argv[1]
    
    # Validate files exist
    if not os.path.exists(problem_file):
        print(f"Error: Problem file '{problem_file}' not found")
        sys.exit(1)
    
    if not os.path.exists('template.cpp'):
        print("Error: template.cpp not found")
        sys.exit(1)
    
    # Read files
    template_content = read_file('template.cpp')
    problem_content = read_file(problem_file)
    
    # Extract problem code
    problem_code = extract_problem_code(problem_content)
    
    # Generate combined solution
    solution = generate_solution(template_content, problem_code)
    
    # Create solutions directory
    solutions_dir = Path('solutions')
    _ = solutions_dir.mkdir(exist_ok=True)
    
    # Write output file
    problem_name = Path(problem_file).stem
    output_file = solutions_dir / f"{problem_name}.cpp"
    
    with open(output_file, 'w') as f:
        _ = f.write(solution)
    
    print(f"✓ Generated: {output_file}")


if __name__ == '__main__':
    main()
