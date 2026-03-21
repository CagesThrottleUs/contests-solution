/*
 *   MIT License
 *
 *   Copyright (c) 2026 CagesThrottleUs
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

struct HeapElement {
  std::int64_t cost;    // NOLINT(misc-non-private-member-variables-in-classes)
  std::int64_t people;  // NOLINT(misc-non-private-member-variables-in-classes)

  auto operator<(const HeapElement& other) const -> bool {
    return cost > other.cost;
  }
};

struct HeapParams {
  std::int64_t num_people;
  std::int64_t direct_cost;
};

auto generate_heap(HeapParams params) -> std::priority_queue<HeapElement> {
  std::vector<std::int64_t> reachability;
  reachability.reserve(static_cast<std::size_t>(params.num_people));

  for (std::int64_t i = 0; i < params.num_people; i++) {
    std::int64_t people{};
    std::cin >> people;
    reachability.push_back(people);
  }

  std::vector<std::int64_t> costs;
  costs.reserve(static_cast<std::size_t>(params.num_people));

  for (std::int64_t i = 0; i < params.num_people; i++) {
    std::int64_t cost{};
    std::cin >> cost;
    costs.push_back(cost);
  }

  std::priority_queue<HeapElement> heap;

  for (std::size_t i = 0; i < reachability.size(); i++) {
    if (costs[i] >= params.direct_cost) {
      continue;
    }
    heap.emplace(costs[i], std::min(reachability[i], params.num_people - 1));
  }
  return heap;
}

auto calc_cost(std::priority_queue<HeapElement> heap, HeapParams params)
    -> std::int64_t {
  std::int64_t total_cost = 0;
  while (!heap.empty() && params.num_people > 1) {
    auto [cost, people] = heap.top();
    heap.pop();
    auto people_to_rem = std::min(people, params.num_people - 1);
    total_cost += cost * people_to_rem;
    params.num_people -= people_to_rem;
  }
  total_cost += params.direct_cost * params.num_people;
  return total_cost;
}

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::int64_t num_people{};
    std::cin >> num_people;
    std::int64_t direct_cost{};
    std::cin >> direct_cost;

    HeapParams params{.num_people = num_people, .direct_cost = direct_cost};

    auto cost = calc_cost(generate_heap(params), params);
    std::cout << cost << "\n";
  }
}