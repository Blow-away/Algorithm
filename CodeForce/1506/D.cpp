#include <iostream>
#include <queue>
#include <map>

void solve() {
    int n;
    std::cin >> n;
    std::priority_queue<std::pair<int, int>> queue;
    std::map<int, int> map;
    for (int i = 0; i < n; ++i) {
        int tmp;
        std::cin >> tmp;
        map[tmp]++;
    }
    for (auto[x, y] : map) {
        queue.push({y, x});
    }
    int ans = n;
    while (queue.size() >= 2) {
        auto [count1, x1] = queue.top();
        queue.pop();
        auto [count2, x2] = queue.top();
        queue.pop();
        count1--;
        count2--;
        ans -= 2;
        if (count1) {
            queue.push({count1, x1});
        }
        if (count2) {
            queue.push({count2, x2});
        }
    }
    std::cout << ans << std::endl;

}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

