# DSA Project Guidelines

## Repository Structure

```
codeforces/   — solve() only, no main
atcoder/      — solve() only, no main
codechef/     — solve() only, no main
leetcode/     — class Solution {} only, no main (LeetCode format)
solutions/    — merged files with main + harness (do not edit manually)
```

**Never add `main` to any problem file.** The `solutions/` harness provides:
- `speedup()` (disables sync, ties null)
- `main()` that calls `solve()` once

`solve()` in each competitive programming problem file reads the test count and loops internally.
`leetcode/` files use `class Solution {}` as expected by the LeetCode judge.

## Compiler & Linter Configuration

### `.clangd`
```yaml
CompileFlags:
  Add:
    - -Wall
    - -Wextra
    - -Wconversion
    - -O2
    - -std=c++23
    - -Werror
```

### `.clang-tidy`
```yaml
Checks: >
  bugprone-*,
  cert-*,
  clang-analyzer-*,
  concurrency-*,
  cppcoreguidelines-*,
  google-*,
  hicpp-*,
  misc-*,
  modernize-*,
  performance-*,
  portability-*,
  readability-*,
  -misc-use-internal-linkage,
```

### Naming Conventions (inferred from existing code)
- Types/structs: `PascalCase`
- Variables, functions, parameters: `snake_case`
- Use `std::size_t` for sizes/indices to avoid `-Wconversion` warnings
- Use `static_cast<std::int64_t>(...)` when converting size types to signed
- Use `0UZ` literal for `std::size_t` zero in C++23 contexts
