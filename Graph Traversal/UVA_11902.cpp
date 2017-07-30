#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define ll long long

int vis[105]={0},vis2[105]={0};
vector<vector<int>> arra(105);

void dfs(int i,int v[] , int x){
    v[i]=1;
    for(int j=0 ; j<(int)arra[i].size() ; j++)
        if(!v[arra[i][j]] and arra[i][j]!=x)
            dfs(arra[i][j],v,x);
}
void out(int x){
    cout<<'+';
    for(int i=0 ; i<x-2 ; i++)
        cout<<'-';
    cout<<'+'<<endl;
}
int main()
{
    int t,v=0;
    cin>>t;
    while(v++<t){
        int n,x;
        cin>>n;
        char ans[n][n];
        vector<int>c;
        memset(ans,'N',sizeof(ans));
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<n ; j++){
                cin>>x;
                if(x)arra[i].push_back(j);
            }
        dfs(0,vis,-1);
        for(int i=0 ; i<n ; i++)
            if(vis[i]){
                c.push_back(i);
                ans[0][i]='Y';
            }
        memset(vis,0,sizeof(vis));
        for(int i=0 ; i<c.size() ; i++){
            dfs(c[i],vis2,-1);
            dfs(0,vis,c[i]);
            for(int j=0 ; j<n ; j++){
                if(vis[j]==0 and vis2[j]==1)
                    ans[c[i]][j]='Y';
            }
            memset(vis2,0,sizeof(vis2));
            memset(vis,0,sizeof(vis));
        }


        cout<<"Case "<<v<<':'<<endl;
        out(2*n+1);
        for(int i=0 ; i<n ; i++){
            cout<<'|';
            arra[i].clear();
            for(int j=0 ; j<n ; j++)
                cout<<ans[i][j]<<'|';
            cout<<endl;
            out(2*n+1);
        }
    }


    return 0;
}
