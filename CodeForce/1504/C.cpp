#include <iostream>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    int count{};
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1')
            count++;
    }
    if (count % 2 || s[0] == '0' || s[n - 1] == '0') {
        std::cout << "NO\n";
        return;
    }
    int k{};
    bool flip = false;
    std::string s1, s2;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            if (k * 2 < count) {
                s1.push_back('(');
                s2.push_back('(');
                ++k;
            } else {
                s1.push_back(')');
                s2.push_back(')');
            }
        } else {
            s1.push_back(flip ? '(' : ')');
            s2.push_back(flip ? ')' : '(');
            flip = !flip;
        }
    }
    std::cout << "YES\n" << s1 << '\n' << s2 << '\n';
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}



