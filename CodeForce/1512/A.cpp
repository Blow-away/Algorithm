#include <iostream>
#include <vector>

void solve() {
    int n{};
    std::cin >> n;
    int ans1{0};
    int ans2{0};
    int num1{0};
    int num2{0};
    int count1{0};
    int count2{0};
    for (int i = 0; i < n; ++i) {
        int temp{};
        std::cin >> temp;
        if (num1 == 0 || temp == num1) {
            num1 = temp;
            count1++;
            if (ans1 == 0)
                ans1 = i + 1;
        } else if (num2 == 0 || temp == num2) {
            num2 = temp;
            count2++;
            if (ans2 == 0)
                ans2 = i + 1;
        }
    }
    if (count1 == 1) {
        std::cout << ans1 << std::endl;
    }
    if (count2 == 1) {
        std::cout << ans2 << std::endl;
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

