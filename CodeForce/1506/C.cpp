#include <iostream>
#include <vector>

// 蛮力
void solve() {
    std::string a, b;
    std::cin >> a >> b;
    int n = a.size(), m = b.size();
    int ans{0};
    for (int len = 1; len <= std::min(m, n); ++len) {
        for (int i = 0; i + len <= n; ++i) {
            for (int j = 0; j + len <= m; ++j) {
                if (a.substr(i, len) == b.substr(j, len)) {
                    ans = std::max(ans, len);
                }
            }
        }
    }
    std::cout << n + m - 2 * ans << std::endl;
}

// dp
void dp() {
    std::string a, b;
    std::cin >> a >> b;
    int n = a.size(), m = b.size();
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0)); // dp[i][j]为a的前i个和b的前j个的最长公共子串的长度
    int max{0};
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                max = std::max(max,dp[i][j]);
            }else{
                dp[i][j] = 0;
            }
        }
    }
    std::cout << m + n - 2 * max << std::endl;
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
//        solve();
        dp();
    }
    return 0;
}

