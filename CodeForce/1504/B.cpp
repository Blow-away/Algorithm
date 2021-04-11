#include <iostream>
#include <string>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    std::string s1, s2;
    std::cin >> s1 >> s2;
    std::vector<int> count(n,0);
    int sum{0};
    for(int i=0;i<n;++i){
        if(s1[i]=='1'){
            sum++;
        }
        count[i] = sum;
    }
    bool reverse = false;
    for(int i=n-1;i>=0;--i){
        if((!reverse&&s1[i]!=s2[i])||(reverse&&s1[i]==s2[i])){
            if(i%2&&count[i]==(i+1)/2) {
                reverse = !reverse;
            }else{
                std::cout<<"NO\n";
                return;
            }
        }
    }
    std::cout<<"YES\n";
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

