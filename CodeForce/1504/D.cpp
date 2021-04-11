#include <iostream>
#include <vector>

using std::cin, std::cout, std::vector;
int c1, c2;

int get(int color1, int color2) {
    if (color1 == 0 || color1 == color2) {
        if (color2 == 3)
            return 1;
        return color2 + 1;
    } else {
        if (color1 > color2)
            std::swap(color1, color2);
        if (color1 == 1 && color2 == 2)
            return 3;
        else if (color1 == 2 && color2 == 3)
            return 1;
        else
            return 2;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<std::pair<int, int>> position1;
    vector<std::pair<int, int>> position2;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if ((i+j)%2==0) {
                position1.emplace_back(i, j);
            } else {
                position2.emplace_back(i, j);
            }
        }
    }
    int a;
    cin >> a;
    c1 = get(0, a);
    int count1 = 0,count2 = 0;
    std::cout << c1 << " " << position1[count1].first << " " << position1[count1++].second << std::endl;
    cin >> a;
    c2 = get(c1, a);
    std::cout << c2 << " " << position2[count2].first << " " << position2[count2++].second << std::endl;
    for (int i = 0; i < n * n - 2; ++i) {
        cin >> a;
        if (count2<position2.size()&&a == c1) {
            std::cout << c2 << " " << position2[count2].first << " " << position2[count2++].second << std::endl;
        } else if (count1<position1.size()&&a == c2) {
            std::cout << c1 << " " << position1[count1].first << " " << position1[count1++].second << std::endl;
        } else {
            if (count2<position2.size()) {
                // 可以填c2，但前提是a!=c2
                std::cout << get(a,c1) << " " << position2[count2].first << " " << position2[count2++].second << std::endl;
            } else {
                std::cout << get(a,c2) << " " << position1[count1].first << " " << position1[count1++].second << std::endl;
            }
        }
    }
}

int main() {
    solve();
    return 0;
}

