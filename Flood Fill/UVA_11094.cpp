#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define ll long long

int dx[4]={ 0,1,0,-1};
int dy[4]={-1,0,1, 0};
int n,m,vis[20][20]={{0}},c=1;
string kelma[20];
char p;

void dfs(int i,int j){
    vis[i][j]=1;
    for(int k=0 ; k<4 ; k++){
        if(i+dx[k]>=0 and i+dx[k]<n and kelma[(i+dx[k]+n)%n][(j+dy[k]+m)%m]==p and !vis[(i+dx[k]+n)%n][(j+dy[k]+m)%m])
            dfs((i+dx[k]+n)%n,(j+dy[k]+m)%m),c++;
    }
}

int main()
{
    while(scanf("%d",&n)!=EOF){
        cin>>m;
        int x,y,maxx=0;
        for(int i=0 ; i<n ; i++)
            cin>>kelma[i];

        cin>>x>>y;
        p = kelma[x][y];
        dfs(x,y);
        c=1;
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<m ; j++){
                if(kelma[i][j]==p and !vis[i][j]){
                    dfs(i,j);
                    maxx=max(maxx,c);
                    c=1;
                }
            }
        cout<<maxx<<endl;
        c=1;
        memset(vis,0,sizeof(vis));
    }

    return 0;
}
