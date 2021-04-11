#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

/**
 * 题意：
 *  数组b为一个n+2大小的数组，其由一个大小为n的数组a产生
 *  b中包含a中所有数
 *  剩余的两个数中，一个数为a的所有数的和，另一个为随机数x(1 <= x <= 1e9)
 *  b是乱序的，也就是不知道多余的两个数的位置
 *  给b，输出a，b无法被任意a产生则输出-1
 */

void solve() {
    int n;
    std::cin >> n;
    long long sum{0};
    std::vector<int> nums;
    for (int i = 0; i < n + 2; ++i) {
        int temp{};
        std::cin >> temp;
        sum += temp;
        nums.emplace_back(temp);
    }
    std::sort(nums.begin(), nums.end());
    auto max1 = nums[nums.size() - 1];
    auto max2 = nums[nums.size() - 2];
    // 如果第二大的数是和，那么x为最大的数
    if (sum - max1 - max2 == max2) {
        for (int i = 0; i < n; ++i) {
            std::cout << nums[i] << " ";
        }
        std::cout << std::endl;
        return;
    }
    for (int i = 0; i < n+1; ++i) {
        if (sum - max1 - nums[i] == max1) {
            // x = nums[i] 最大的数是和
            nums[i] = 0;
            nums[nums.size() - 1] = 0;
            for (auto j:nums) {
                if (j != 0)
                    std::cout << j << " ";
            }
            std::cout << std::endl;
            return;
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

