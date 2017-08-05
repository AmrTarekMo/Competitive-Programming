#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long
#define ii pair<int,int>

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};

bool vis[1000]={0};
priority_queue<ii>q;
vector<vector<ii>> edge(1000);
void solve(int i){
    vis[i] = 1;
    for(int j=0 ; j<(int)edge[i].size() ; j++ ){
        if(!vis[edge[i][j].F])
            q.push({-edge[i][j].S,-edge[i][j].F});
    }
}

int main()
{
    int mst=0,u,w,e,v,x,y,z;
    for(int i=0 ; i<e ; i++){
        cin>>x>>y>>z;
        edge[x].push_back({y,z}); // x vertix , y vertix , z weight
        edge[y].push_back({x,z});//  bi-directional
        ans+=z;
    }
    solve(0);
    while(!q.empty()){
        ii a = q.top();q.pop();
        u = -a.S; w = -a.F;
        if(!vis[u]){
            mst += w;
            solve(u);
        }
    }
    return 0;
}
