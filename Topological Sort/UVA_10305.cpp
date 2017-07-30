#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};
int n,m,vis[105]={0};
vector<vector<int>> arra(105);
vector<int>topsort;
void dfs(int i){
    vis[i]=1;
    for(int j=0 ; j<(int)arra[i].size() ; j++)
        if(!vis[arra[i][j]])
            dfs(arra[i][j]);
    topsort.push_back(i);
}
int main()
{
    while(scanf("%d%d",&n,&m) and n!=0 or m!=0){
        int x,y;
        for(int i=0 ; i<m ; i++){
            cin>>x>>y;
            arra[x].push_back(y);
        }
        for(int i=1 ; i<=n ; i++)
            if(!vis[i])
                dfs(i);
        for(int i=n-1 ; i>=0 ; i--)
            cout<<topsort[i]<<" \n"[i == 0];
        memset(vis,0,sizeof(vis));
        topsort.clear();
        for(int i=1 ; i<=n ; i++)arra[i].clear();
    }

    return 0;
}
