#include <cstddef>
#include <cstdint>
#include <string>
#include <utility>
#include <vector>

namespace constants {
constexpr std::int64_t BASE = 10;
constexpr std::int64_t MOD = 1'000'000'000 + 7;
};  // namespace constants

struct OperandsParam {
  std::int64_t digits;
  std::size_t width;
};

class Solution {
 private:
  static auto determine_operands(const OperandsParam& param)
      -> std::pair<std::int64_t, std::int64_t> {
    auto str = std::to_string(param.digits);
    auto first = std::stoll(str.substr(0, param.width));
    auto last = std::stoll(str.substr(param.width));
    return std::make_pair(first, last);
  }

  static auto binary_exponentiation(
      std::pair<std::int64_t, std::int64_t> param) -> std::int64_t {
    std::int64_t res = 1;
    param.first %= constants::MOD;

    while (param.second > 0) {
      // NOLINTNEXTLINE(hicpp-signed-bitwise)
      if ((param.second & 1LL) == 1) {
        res = (res * param.first) % constants::MOD;
      }
      param.first = (param.first * param.first) % constants::MOD;
      // NOLINTNEXTLINE(hicpp-signed-bitwise)
      param.second >>= 1;
    }

    return res;
  }

 public:
  // Changed std::vector<std::int64_t>& to const std::vector<long long>&
  // NOLINTNEXTLINE(google-runtime-int)
  static auto sumDecoded(const std::vector<long long>& nums) -> int {
    std::int64_t sum{0};
    for (const auto& num : nums) {
      auto width = num % constants::BASE;
      auto digits = num / constants::BASE;

      auto exp_params = determine_operands(
          {.digits = digits, .width = static_cast<std::size_t>(width)});

      auto exp_res = binary_exponentiation(exp_params);

      sum += exp_res;
      sum %= constants::MOD;
    }

    return static_cast<std::int32_t>(sum);
  }
};