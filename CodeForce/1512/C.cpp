#include <iostream>
#include <string>

/**
 * 题意：
 *  一个串s由 0 1 ? 组成
 *  问是否可以修改?为0或1使s变为回文串
 *  能输出回文串
 *  不能输出 -1
 */
void solve() {
    int a{}, b{};
    std::cin >> a >> b;
    std::string s;
    std::cin >> s;
    int count0{0};
    int count1{0};
    int n = s.length();
    if (a + b != n) {
        std::cout << -1 << std::endl;
        return;
    }
    for (int i = 0; i < (n + 1) / 2; ++i) {

        if (s[i] == s[n - i - 1]) {
            if (s[i] == '0') {
                if (i == n - i - 1)
                    count0++;
                else
                    count0 += 2;
            } else if (s[i] == '1') {
                if (i == n - i - 1)
                    count1++;
                else
                    count1 += 2;
            }
        } else {
            if (s[i] == '?') {
                s[i] = s[n - i - 1];
            } else if (s[n - i - 1] == '?') {
                s[n - i - 1] = s[i];
            } else {
                std::cout << -1 << std::endl;
                return;
            }
            if (s[i] == '0') {
                count0 += 2;
            } else {
                count1 += 2;
            }
        }
    }
    for (int i = 0; i < (n + 1) / 2; ++i) {
        if (count0 > a || count1 > b) {
            std::cout << -1 << std::endl;
            return;
        }
        if (s[i] == '?' && s[n - i - 1] == '?') {
            if (a - count0 > b - count1) {
                if (i == n - i - 1)
                    count0 += 1;
                else
                    count0 += 2;
                s[i] = s[n - i - 1] = '0';
            } else {
                if (i == n - i - 1)
                    count1 += 1;
                else
                    count1 += 2;
                s[i] = s[n - i - 1] = '1';
            }

        }
    }
    if (count0 != a || count1 != b) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << s << std::endl;
    }
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}



