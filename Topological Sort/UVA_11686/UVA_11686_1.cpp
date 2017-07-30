#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long
int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};

int vis[1000005]={0},n,m,a,b,timer=0 , sta[1000005]={0},fin[1000005]={0},flag=true;
vector<vector<int>> arra(1000005);
vector<int>topsort;

bool dfs(int i){
    timer++;
    vis[i]=1;
    sta[i]=timer;
    for(int j=0 ; j<(int)arra[i].size() ; j++){
        if(!vis[arra[i][j]]){
            if(!dfs(arra[i][j]))return false;}
        else{
            if(fin[arra[i][j]]==0)
                return false;
        }
    }
    fin[i]=timer;
    topsort.push_back(i);
    return true;
}

int main()
{
    while(cin>>n>>m and (n!=0 or m!=0 )){
        for(int i=0 ; i<m ; i++){
            cin>>a>>b;
            arra[a].push_back(b);
        }
        for(int i=1 ; i<=n ; i++ )
            if(!vis[i] and !dfs(i)){
                cout<<"IMPOSSIBLE"<<endl;
                flag = false;
                break;
            }

        if(flag)
        for(int i=topsort.size()-1 ; i>=0 ; i--)
            cout<<topsort[i]<<'\n';

        for(int i=0 ; i<=n ; i++)arra[i].clear();
        memset(fin,0,sizeof(fin));
        memset(sta,0,sizeof(sta));
        memset(vis,0,sizeof(vis));
        topsort.clear();
        flag=true;
        timer=0;
    }

    return 0;
}
