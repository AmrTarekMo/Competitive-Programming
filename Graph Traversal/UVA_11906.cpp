#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define ll long long

int vis[105][105]={{0}},grid[105][105]={{0}},a,b,n,m;
set< pair<int,int> > arra[105][105];
void dfs(int i , int j){
    grid[i][j]++;
    if( i-a <n and i-a>=0 and j-b<m and j-b>=0 and vis[i-a][j-b]!=-1){
        arra[i][j].insert(make_pair(i-a,j-b));
        if(grid[i-a][j-b]==0)dfs(i-a,j-b);
    }
    if( i+a <n and i+a>=0 and j+b<m and j+b>=0 and vis[i+a][j+b]!=-1){
        arra[i][j].insert(make_pair(i+a,j+b));
        if(grid[i+a][j+b]==0)dfs(i+a,j+b);
    }
    if( i+a <n and i+a>=0 and j-b<m and j-b>=0 and vis[i+a][j-b]!=-1){
        arra[i][j].insert(make_pair(i+a,j-b));
        if(grid[i+a][j-b]==0)dfs(i+a,j-b);
    }
    if( i-a <n and i-a>=0 and j+b<m and j+b>=0 and vis[i-a][j+b]!=-1){
        arra[i][j].insert(make_pair(i-a,j+b));
        if(grid[i-a][j+b]==0)dfs(i-a,j+b);
    }
    if( i-b <n and i-b>=0 and j-a<m and j-a>=0 and vis[i-b][j-a]!=-1){
        arra[i][j].insert(make_pair(i-b,j-a));
        if(grid[i-b][j-a]==0)dfs(i-b,j-a);
    }
    if( i+b <n and i+b>=0 and j+a<m and j+a>=0 and vis[i+b][j+a]!=-1){
        arra[i][j].insert(make_pair(i+b,j+a));
        if(grid[i+b][j+a]==0)dfs(i+b,j+a);
    }
    if( i-b <n and i-b>=0 and j+a<m and j+a>=0 and vis[i-b][j+a]!=-1){
        arra[i][j].insert(make_pair(i-b,j+a));
        if(grid[i-b][j+a]==0)dfs(i-b,j+a);
    }
    if( i+b <n and i+b>=0 and j-a<m and j-a>=0 and vis[i+b][j-a]!=-1){
        arra[i][j].insert(make_pair(i+b,j-a));
        if(grid[i+b][j-a]==0)dfs(i+b,j-a);
    }
}

int main()
{
    int t,v=0;
    cin>>t;
    while(v++ < t){
        int c,x,y,even=0,odd=0;
        cin>>n>>m>>a>>b>>c;
        memset(vis,0 ,sizeof(vis));
        memset(grid,0,sizeof(grid));
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<m ; j++)
                arra[i][j].clear();
        while(c--){
            cin>>x>>y;
            vis[x][y]=-1;
        }
        dfs(0,0);
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<m ; j++)
                if(vis[i][j]==0)
                    vis[i][j]=arra[i][j].size();
        vis[0][0]+=2;
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<m ; j++){
                if(vis[i][j]>0)
                    vis[i][j]%2==0?even++:odd++;
            }
        cout<<"Case "<<v<<": "<<even<<' '<<odd<<endl;
    }

    return 0;
}
