#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long
int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};

int main()
{
    int n,m,a,b;
    while(scanf("%d",&n) and n!=0){
        scanf("%d",&m);
        vector<vector<int>>arra(n);
        queue<int>q;
        int vis[n],flag=true;
        memset(vis,-1,sizeof(vis));
        for(int i=0 ; i<m ; i++){
            scanf("%d%d",&a,&b);
            arra[a].push_back(b);
            arra[b].push_back(a);
        }
        q.push(0);
        vis[0]=0;
        while(!q.empty() and flag){
            a = q.front();q.pop();
            for(int i=0 ; i<(int)arra[a].size() ; i++){
                b = arra[a][i];
                if(vis[b] == -1){
                    vis[b] = 1-vis[a];
                    q.push(b);
                }
                else if(vis[b] == vis[a]){
                    flag = false;
                    break;
                }
            }
        }
        if(flag)printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }


    return 0;
}
