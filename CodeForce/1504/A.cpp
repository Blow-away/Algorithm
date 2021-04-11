#include <iostream>
#include <string>

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    for(int i=0;i<n+1;++i){
        if(n-i-1>=0&&s[n-i-1]!='a'){
            std::cout<<"YES\n";
            std::cout<<s.substr(0,i)+"a"+s.substr(i)<<'\n';
            return;
        }
    }
    std::cout<<"NO\n";
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}
