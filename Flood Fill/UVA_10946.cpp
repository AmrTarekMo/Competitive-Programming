#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define ll long long

int dx[4]={ 0,1,0,-1};
int dy[4]={-1,0,1, 0};
int n,m,vis[51][51]={0},c=1;
string kelma[51];

void dfs(int i,int j){
    vis[i][j]=1;
    for(int k=0 ; k<4 ; k++){
        if(i+dx[k]>=0 and i+dx[k]<n and j+dy[k]>=0 and j+dy[k]<m and !vis[i+dx[k]][j+dy[k]] and kelma[i][j]==kelma[i+dx[k]][j+dy[k]])
            dfs(i+dx[k],j+dy[k]),c++;
    }
}

int main()
{
    int t=0;
    while(++t and cin>>n>>m and n!=0 and m!=0){
        vector<vector<int>>arra(27);
        for(int i=0 ; i<n ; i++)
            cin>>kelma[i];

        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<m ; j++)
                if(kelma[i][j]!='.' and !vis[i][j]){
                    dfs(i,j);
                    arra[kelma[i][j]-'A'].push_back(c);
                    c=1;
                }
        printf("Problem %d:\n",t);
        for(int i=50*50 ; i>0 ; i--)
            for(int j=0 ; j<26 ; j++)
                for(int k=0 ; k<arra[j].size() ; k++)
                    if(arra[j][k]==i){
                        cout<<char(j+'A')<<' '<<arra[j][k]<<endl;
                        arra[j][k]=0;
                    }
        memset(vis,0,sizeof(vis));
    }
    return 0;
}
