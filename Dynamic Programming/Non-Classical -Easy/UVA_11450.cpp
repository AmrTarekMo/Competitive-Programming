#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long
#define ii pair<int,int>

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};

int hold,n,memo[202][22];
vector<vector<int>>arra(22);
int solve(int money , int lvl){
    if(money < 0 )return -100000;
    if(lvl == n)return hold-money;

    if(memo[money][lvl] != -1)return memo[money][lvl];
    int maxx = -1;
    for(int i=0 ; i<arra[lvl].size() ; i++){
        maxx = max(maxx , solve(money-arra[lvl][i] , lvl+1));
    }
    return memo[money][lvl] = maxx ;
}

int main()
{
    int t,k,x;
    scanf("%d",&t);
    while(t-- and scanf("%d%d",&hold,&n)){
        for(int i=0 ; i<n ; ++i){
            scanf("%d",&k);
            for(int j=0 ; j<k ; j++){
                scanf("%d",&x);
                arra[i].push_back(x);
            }
        }
        memset(memo,-1,sizeof(memo));
        int ans = solve(hold , 0);
        if(ans<0)printf("no solution\n");
        else printf("%d\n",ans);

        for(int i=0 ; i<n ; i++)arra[i].clear();
    }

    return 0;
}
