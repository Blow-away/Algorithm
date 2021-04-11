#include <iostream>
#include <vector>
#include <queue>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int tmp;
        std::cin >> tmp;
        nums.emplace_back(tmp);
    }
    std::priority_queue<int> max;
    std::priority_queue<int, std::vector<int>, std::greater<>> min;
    std::vector<int> ans_max;
    std::vector<int> ans_min;
    int now = 0;
    int last;
    for (int i = 0; i < n; ++i) {
        if (i==0||nums[i] != now) {
            last = now;
            now = nums[i];
            for (int i = last + 1; i <= now - 1; ++i) {
                max.push(i);
                min.push(i);
            }
            ans_max.emplace_back(now);
            ans_min.emplace_back(now);
            continue;
        }
        ans_max.emplace_back(max.top());
        max.pop();
        ans_min.emplace_back(min.top());
        min.pop();
    }
    for (auto i:ans_min) {
        std::cout << i << " ";
    }
    std::cout << '\n';
    for (auto i:ans_max) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

