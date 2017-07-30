#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define ll long long

int dx[8]={ 0, 1,1,1,0,-1,-1,-1};
int dy[8]={-1,-1,0,1,1, 1, 0,-1};

int vis[26][26]={0},c=1,n,m;
string kelma[26];
bool dfs(int i , int j){
    vis[i][j]=1;

    for(int k=0 ; k<8 ; k++){
        if(i+dx[k]>=0 and i+dx[k]<n and j+dy[k]>=0 and j+dy[k]<m and kelma[i+dx[k]][j+dy[k]]=='1' and !vis[i+dx[k]][j+dy[k]])
            dfs(i+dx[k],j+dy[k]),c++;
    }
}

int main()
{
    int t;
    string in;
    cin>>t;
    cin.ignore();
    getline(cin,in);
    while(t--){
        int z=0,maxx=0;
        while(getline(cin,in) and in!=""){
            kelma[z]=in;
            z++;
        }
        n=z;m=kelma[0].size();
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<m ; j++)
                if(kelma[i][j]=='1' and vis[i][j]==0){
                    dfs(i,j);
                    maxx = max(c,maxx);
                    c=1;
                }
        cout<<maxx<<endl;
        if(t!=0)cout<<endl;
        memset(vis,0,sizeof(vis));
    }
    return 0;
}
