#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define ll long long

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};

int vis[10005]={0},n,k,l;
vector<vector<int>> arra(10005);
void dfs(int i){
    vis[i]=1;
    for(int j=0 ; j<(int)arra[i].size() ; j++)
        if(!vis[arra[i][j]])
            dfs(arra[i][j]);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int x,y,c=0;
        cin>>n>>k>>l;
        for(int i=0 ; i<k ; i++){
            cin>>x>>y;
            arra[x].push_back(y);
        }
        for(int i=0 ; i<l ; i++){
            cin>>x;
            if(!vis[x])dfs(x);
        }
        for(int i=0 ; i<=n ; i++)
            if(vis[i])c++;
        cout<<c<<endl;
        memset(vis,0,sizeof(vis));
        for(int i=1 ; i<=n ; i++)
            arra[i].clear();
    }


    return 0;
}
