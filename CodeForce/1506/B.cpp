#include <iostream>
#include <string>
#include <vector>

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int n, k;
        std::cin >> n >> k;
        std::string s;
        std::cin >> s;
        std::vector<int> indexs;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*')
                indexs.emplace_back(i);
        }
        if (indexs.size() <= 2) {
            std::cout << indexs.size() << std::endl;
            continue;
        }
        int ans{2};
        int later = indexs[0];
        for (int i = 1; i < indexs.size() - 1; ++i) {
            int now = indexs[i];
            int former = indexs[i + 1];
            if (now - later > k || former - later > k) {
                ans++;
                later=now;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}

