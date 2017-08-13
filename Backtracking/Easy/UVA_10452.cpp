#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long
#define ii pair<int,int>

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};

vector<string>ans;
int n,m,vis[10][10]={0};
bool solve(string arra[] , int i, int j ){
    if(arra[i][j]=='#'){
        return true;
    }
    vis[i][j]=1;
    if(i-1>=0 and (arra[i-1][j]=='I' or arra[i-1][j]=='E' or arra[i-1][j]=='H' or
            arra[i-1][j]=='O' or arra[i-1][j]=='V' or arra[i-1][j]=='A' or arra[i-1][j]=='#') and !vis[i-1][j] and solve(arra,i-1,j)){
        ans.push_back("forth");
        return true;
    }
    if(j-1>=0 and (arra[i][j-1]=='I' or arra[i][j-1]=='E' or arra[i][j-1]=='H' or
                   arra[i][j-1]=='O' or arra[i][j-1]=='V' or arra[i][j-1]=='A' or arra[i][j-1]=='#') and !vis[i][j-1] and solve(arra,i,j-1)){
        ans.push_back("left");
        return true;
    }
    if(j+1<m and (arra[i][j+1]=='I' or arra[i][j+1]=='E' or arra[i][j+1]=='H' or
                   arra[i][j+1]=='O' or arra[i][j+1]=='V' or arra[i][j+1]=='A' or arra[i][j+1]=='#') and !vis[i][j+1] and solve(arra,i,j+1)){
        ans.push_back("right");
        return true;
    }
    vis[i][j]=0;
    return false;
}


int main()
{
    int t,x,y;
    scanf("%d",&t);
    while( t-- and scanf("%d%d",&n,&m) ){
        string kelma[n];
        for(int i=0 ; i<n ; i++)
            cin>>kelma[i];
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<m ; j++)
                if(kelma[i][j]=='@'){x=i,y=j;break;}
        solve(kelma,x,y);
        for(int i=ans.size()-1 ; i>=0 ; i--)
            cout<<ans[i]<<" \n"[i == 0];
        ans.clear();
        memset(vis,0,sizeof(vis));
    }

    return 0;
}
