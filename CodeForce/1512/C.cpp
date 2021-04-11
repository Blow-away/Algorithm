#include <iostream>
#include <string>

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
    for (const auto &i:s) {
        if (i == '0')
            count0++;
        else if (i == '1')
            count1++;
    }
    if (count0 > a || count1 > b) {
        std::cout << -1 << std::endl;
        return;
    }
    for (int i = 0; i <= n / 2; ++i) {
        if (count0 > a || count1 > b) {
            std::cout << -1 << std::endl;
            return;
        }
        if (s[i] == '?') { //? -> x
            if (s[n - i - 1] == '?') { //-> ?
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
            } else if (s[n - i - 1] == '0') {// -> 0
                count0++;
                s[i] = '0';
            } else {// -> 1
                count1++;
                s[i] = '1';
            }
        } else if (s[i] == '0') {

            if (s[n - i - 1] == '?') {
                count0++;
                s[n - i - 1] = '0';
            } else if (s[n - i - 1] != '0') {
                std::cout << -1 << std::endl;
                return;
            }
        } else { // 1 -> x
            if (s[n - i - 1] == '?') {
                count1++;
                s[n - i - 1] = '1';
            } else if (s[n - i - 1] != '1') {
                std::cout << -1 << std::endl;
                return;
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



