#include <iostream>

int main() {
    int T;
    std::cin>>T;
    while(T--){
        int n,m;
        std::cin>>n>>m;
        long long number;
        std::cin>>number;
        long long ans{0};
        long long col{0},row{0};
        col = static_cast<long long>(number / n) + 1;
        row = number%n;
        if(!row){
            row = n;
            col -=1;
        }
        ans = (row-1)*m + col;
        std::cout<<ans<<std::endl;
    }
    return 0;
}

