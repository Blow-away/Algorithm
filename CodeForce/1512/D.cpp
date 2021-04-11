#include <iostream>
#include <unordered_map>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    std::unordered_map<int, int> map;
    long long sum{0};
    std::vector<int> nums;
    for (int i = 0; i < n + 2; ++i) {
        int temp{};
        std::cin >> temp;
        sum += temp;
        map[temp] = 1;
        nums.emplace_back(temp);
    }
    for (int i = 0; i < n + 2; ++i) {
        if(map.find(sum-nums[i])!=map.end()){
            int temp = sum-nums[i];
            nums[]
        }
    }
    std::cout << -1 << std::endl;
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

