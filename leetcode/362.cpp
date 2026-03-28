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

#include <array>
#include <numeric>

constexpr int TIME_WINDOW = 300;

// Bucket-based design: O(1) hit(), O(TIME_WINDOW) getHits(), O(TIME_WINDOW)
// space. Scales to arbitrary hit rates — all hits at the same second collapse
// into one counter.
class HitCounter {
  struct Bucket {
    int timestamp{0};
    int count{0};
  };

  std::array<Bucket, TIME_WINDOW> buckets_{};

 public:
  HitCounter() = default;

  void hit(int timestamp) {
    auto& bucket =
        buckets_.at(static_cast<std::size_t>(timestamp % TIME_WINDOW));
    if (bucket.timestamp == timestamp) {
      ++bucket.count;
    } else {
      bucket = {.timestamp = timestamp, .count = 1};
    }
  }

  auto getHits(int timestamp) -> int {
    return std::accumulate(
        buckets_.begin(), buckets_.end(), 0,
        [cutoff = timestamp - TIME_WINDOW](int sum, const Bucket& bkt) -> int {
          return sum + (bkt.timestamp > cutoff ? bkt.count : 0);
        });
  }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */