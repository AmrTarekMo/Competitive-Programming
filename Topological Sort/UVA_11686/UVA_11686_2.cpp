#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long
int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};

int vis[1000005]={0},n,m,a,b,ind[1000005]={0};
vector<vector<int>> arra(1000005);
vector<int>top;

bool khan(){
    for(int i=0 ; i<top.size() ; i++){
        a = top[i];
        for(int j=0 ; j<arra[a].size() ; j++){
            ind[arra[a][j]]--;
            if(!ind[arra[a][j]])
                top.push_back(arra[a][j]);
        }
    }
    return (top.size() == n);
}

int main()
{
    while(scanf("%d%d",&n,&m) and (n!=0 or m!=0 )){
        for(int i=0 ; i<m ; i++){
            scanf("%d%d",&a,&b);
            arra[a].push_back(b);
            ind[b]++;
        }
        for(int i=1 ; i<=n ; i++)
            if(!ind[i])top.push_back(i);
        if(!khan())printf("IMPOSSIBLE\n");
        else
            for(int i=0 ; i<n ; i++)
                printf("%d\n",top[i]);

        for(int i=0 ; i<=n ; i++)arra[i].clear();
        memset(vis,0,sizeof(vis));
        memset(ind,0,sizeof(ind));
        top.clear();
    }

    return 0;
}
