#include <iostream>
#include <vector>


void init(std::vector<std::vector<int>>& cost,int n){
    std::vector<std::pair<int,int>> tmp;
    while(n--){
        int a,c;
        std::cin>>a>>c;
        tmp.emplace_back(a,c);
    }
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j){
            if(i==j){
                cost[i+1][j+1] = -1;
            }else{
                cost[i+1][j+1] = std::max(tmp[i].second,tmp[j].first-tmp[i].first);
            }
        }
}

int main() {
    int n;
    std::cin>>n;
    std::vector<std::vector<int>> cost(n+1,std::vector<int>(n+1,0));
    init(cost,n);

    return 0;
}



