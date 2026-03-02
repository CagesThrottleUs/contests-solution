#include <iostream>
#include <string>
#include <vector>

// State: (start_char, len). start_char: 0='a', 1='b'.
static int end_char(int start_char, int str_len) {
  if (str_len % 2 == 0) {
    return 1 - start_char;
  }
  return start_char;
}

bool work() {
  int n{};
  std::cin >> n;

  std::string str{};
  std::cin >> str;

  const int cap = n + 1;
  const size_t size = static_cast<size_t>(2 * cap);

  std::vector<bool> cur(size, false);
  cur[0 * cap + n] = true;

  std::vector<int> cur_c, cur_len;
  cur_c.push_back(0);
  cur_len.push_back(n);

  for (int i = 0; i < n; ++i) {
    std::vector<bool> next(size, false);
    std::vector<int> next_c, next_len;
    next_c.reserve(size);
    next_len.reserve(size);

    const char need = str[static_cast<size_t>(i)];

    for (size_t j = 0; j < cur_c.size(); ++j) {
      const int c = cur_c[j];
      const int len = cur_len[j];
      if (len == 0) {
        continue;
      }
      const int new_len = len - 1;
      const int e = end_char(c, len);
      const int other = 1 - c;

      auto add = [&](int nc, int nlen) {
        const size_t idx = static_cast<size_t>(nc * cap + nlen);
        if (!next[idx]) {
          next[idx] = true;
          next_c.push_back(nc);
          next_len.push_back(nlen);
        }
      };

      if (need == '?' || need == 'a') {
        if (c == 0) {
          add(other, new_len);
        }
        if (e == 0) {
          add(c, new_len);
        }
      }
      if (need == '?' || need == 'b') {
        if (c == 1) {
          add(other, new_len);
        }
        if (e == 1) {
          add(c, new_len);
        }
      }
    }

    cur = std::move(next);
    cur_c = std::move(next_c);
    cur_len = std::move(next_len);
  }

  return cur[0] || cur[static_cast<size_t>(cap)];
}

void solve() {
  int num_test_case{};
  std::cin >> num_test_case;

  while (num_test_case > 0) {
    num_test_case--;
    auto sol = work();
    if (sol) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}