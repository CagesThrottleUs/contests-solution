#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class MyContainer {
private:
    std::vector<std::vector<int>> all_blogs;
    std::unordered_set<int> seen;

    // Helper to remove seen elements from a single vector
    void clean_vector(std::vector<int>& v) {
        v.erase(std::remove_if(v.begin(), v.end(),
                               [this](int x) { return seen.count(x); }),
                v.end());
    }

public:
    void push(std::vector<int>&& sorted_people) {
        all_blogs.push_back(std::move(sorted_people));
    }

    void print() {
        bool global_first = true;
        seen.clear();

        while (!all_blogs.empty()) {
            int best_idx = -1;

            // 1. Find the best vector using Lazy Filtering
            for (int i = 0; i < (int)all_blogs.size(); ++i) {
                clean_vector(all_blogs[i]);
                
                if (all_blogs[i].empty()) {
                    // Remove empty vectors by swapping with the end
                    std::swap(all_blogs[i], all_blogs.back());
                    all_blogs.pop_back();
                    i--; // Re-check this index
                    continue;
                }

                if (best_idx == -1 || all_blogs[i] < all_blogs[best_idx]) {
                    best_idx = i;
                }
            }

            if (best_idx == -1) break;

            // 2. Extract the winner
            std::vector<int> winner = std::move(all_blogs[best_idx]);
            std::swap(all_blogs[best_idx], all_blogs.back());
            all_blogs.pop_back();

            // 3. Print and update seen
            for (int val : winner) {
                // Double check 'seen' because winner might have internal duplicates 
                // or elements that became 'seen' during the loop
                if (seen.insert(val).second) {
                    if (!global_first) std::cout << " ";
                    std::cout << val;
                    global_first = false;
                }
            }
        }
    }
};

void work() {
    int num_posts{};
    if (!(std::cin >> num_posts)) return;

    MyContainer pq;
    for (int i = 0; i < num_posts; i++) {
        std::size_t people_count{};
        std::cin >> people_count;

        // Use a vector of pairs to preserve original index and handle duplicates
        std::unordered_map<int, int> last_pos;
        for (int j = 0; j < (int)people_count; j++) {
            int person;
            std::cin >> person;
            last_pos[person] = j; // Only keep the last occurrence
        }

        std::vector<std::pair<int, int>> temp;
        temp.reserve(last_pos.size());
        for (auto const& [id, pos] : last_pos) {
            temp.push_back({id, pos});
        }

        // Sort by position descending
        std::sort(temp.begin(), temp.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        std::vector<int> sorted_people;
        sorted_people.reserve(temp.size());
        for (auto const& p : temp) sorted_people.push_back(p.first);

        pq.push(std::move(sorted_people));
    }

    pq.print();
    std::cout << "\n";
}

void solve() {
  int num_test_cases{};
  std::cin >> num_test_cases;
  while (num_test_cases--) {
    work();
  }
}