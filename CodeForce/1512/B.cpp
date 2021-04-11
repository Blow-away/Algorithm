#include <iostream>
#include <vector>

void solve() {
    int n{};
    std::cin >> n;
    std::vector<std::vector<char>> angle;
    int col[2], row[2];
    bool first = true;
    for (int i = 0; i < n; ++i) {
        angle.emplace_back(std::vector<char>());
        for (int j = 0; j < n; ++j) {
            char temp{};
            std::cin >> temp;
            angle[i].emplace_back(temp);
            if (temp == '*') {
                if (first) {
                    row[0] = i;
                    col[0] = j;
                    first = !first;
                } else {
                    row[1] = i;
                    if(row[1]==row[0])
                        row[1] = (row[1]+1)%n;
                    col[1] = j;
                    if(col[1]==col[0])
                        col[1] = (col[1]+1)%n;
                }
            }
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            angle[row[i]][col[j]] = '*';
        }
    }
    for (const auto& i : angle) {
        for (const auto& j:i) {
            std::cout << j;
        }
        std::cout << '\n';
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

