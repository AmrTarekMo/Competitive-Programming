#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long
int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};

int n,a,b,vis[305]={0};
vector< vector<int> >arra(305);

int main()
{
    while(scanf("%d",&n) and n!=0 ){
        while(scanf("%d%d",&a,&b) and (a!=0 or b!=0)){
            arra[a].push_back(b);
            arra[b].push_back(a);
        }
        bool flag = true;
        queue<int>q;
        memset(vis,-1,sizeof(vis));
        for(int j=1 ; j<=n and flag ; j++){
            if(vis[j]!=-1)continue;
            q.push(j);
            vis[j]=0;
            while(!q.empty() and flag){
                a = q.front();q.pop();
                for(int i=0 ; i<(int)arra[a].size() ; i++){
                    b = arra[a][i];
                    if(vis[b] == -1){
                        vis[b] = 1 - vis[a];
                        q.push(b);
                    }
                    else if(vis[b] == vis[a]){
                        flag = false;
                        break;
                    }}
            }
        }
        if(flag)printf("YES\n");
        else printf("NO\n");
        for(int i=0 ; i<=n ; i++)arra[i].clear();
    }

    return 0;
}
