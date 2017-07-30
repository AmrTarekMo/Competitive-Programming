#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define ll long long

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};
int n,m,vis[51][51]={{0}},c=0;
string kelma[51];
void dfs(int i , int j){
    vis[i][j]=1;
    for(int k=0 ; k<8 ; k+=2)
        if(i+dx[k]<n and i+dx[k]>=0 and j+dy[k]<m and j+dy[k]>=0 and kelma[i+dx[k]][j+dy[k]]=='T')return ;

    for(int k=0 ; k<8 ; k+=2)
        if(i+dx[k]<n and i+dx[k]>=0 and j+dy[k]<m and j+dy[k]>=0)
            if((kelma[i+dx[k]][j+dy[k]]=='.' or kelma[i+dx[k]][j+dy[k]]=='G') and !vis[i+dx[k]][j+dy[k]] ){
                if(kelma[i+dx[k]][j+dy[k]]=='G')c++;
                dfs(i+dx[k],j+dy[k]);
            }
}

int main()
{
    while(scanf("%d%d",&m,&n)!=EOF){
        for(int i=0 ; i<n ; i++)
            cin>>kelma[i];
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<m ; j++)
                if(kelma[i][j]=='P')
                    dfs(i,j);
        cout<<c<<endl;
        memset(vis,0,sizeof(vis));
        c=0;
    }


    return 0;
}
