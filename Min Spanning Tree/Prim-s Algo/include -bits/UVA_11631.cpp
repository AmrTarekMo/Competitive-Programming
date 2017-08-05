#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long
#define ii pair<int,int>

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};
bool vis[100002]={0};
priority_queue<ii>q;
vector<vector<ii>> edge(100002);
void solve(int i){
    vis[i] = 1;
    for(int j=0 ; j<(int)edge[i].size() ; j++ ){
        if(!vis[edge[i][j].F])
            q.push({-edge[i][j].S,-edge[i][j].F});
    }
}

int main()
{
    int x,y,z,n,m;
    while(scanf("%d%d",&n,&m) and n+m!=0){
        int ans=0 , mst=0,u,w;
        for(int i=0 ; i<m ; i++){
            cin>>x>>y>>z;
            edge[x].push_back({y,z});
            edge[y].push_back({x,z});
            ans+=z;
        }
        solve(0);
        while(!q.empty()){
            ii x = q.top();q.pop();
            u = -x.S; w = -x.F;
            if(!vis[u]){
                mst += w;
                solve(u);
            }
        }
        cout<<ans-mst<<endl;
        memset(vis,false,sizeof(vis));
        for(int i=0 ;i<100002;i++)edge[i].clear();

    }


    return 0;
}
