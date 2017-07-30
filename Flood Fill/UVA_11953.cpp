#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define ll long long

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};
int vis[105][105]={{0}},n;
string kelma[105];

void dfs(int i,int j){
    vis[i][j]=1;
    for(int k=0 ; k<8 ; k+=2)
        if(i+dx[k]<n and i+dx[k]>=0 and j+dy[k]<n and j+dy[k]>=0 and (kelma[i+dx[k]][j+dy[k]]=='x' or kelma[i+dx[k]][j+dy[k]]=='@') and !vis[i+dx[k]][j+dy[k]])
            dfs(i+dx[k],j+dy[k]);
}

int main()
{
    int t,v=0;
    scanf("%d",&t);
    while(v++<t){
        scanf("%d",&n);
        int c=0;
        for(int i=0 ; i<n ; ++i)
            cin>>kelma[i];
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<n ; j++)
                if(!vis[i][j] and kelma[i][j]=='x'){
                    dfs(i,j);
                    c++;
                }
        printf("Case %d: %d\n",v,c);
        memset(vis,0,sizeof(vis));

    }
    
    return 0;
}
