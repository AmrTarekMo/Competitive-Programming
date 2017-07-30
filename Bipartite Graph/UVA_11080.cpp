#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long
int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};

int n,a,b,m,vis[205];
vector<vector<int>>arra(205);
int main()
{
    int t;
    scanf("%d",&t);
    while(t-- and scanf("%d%d",&n,&m)){
        for(int i=0 ; i<m ; i++){
            scanf("%d%d",&a,&b);
            arra[a].push_back(b);
            arra[b].push_back(a);
        }
        int flag = true , ans=0;
        queue<int>q;
        memset(vis,-1,sizeof(vis));
        for(int j=0 ; j<n and flag ; j++){
            if(vis[j]!=-1)continue;
            int c=0 , c1=0;
            q.push(j);
            vis[j]=0;
            c++;
            while(!q.empty() and flag){
                a = q.front();q.pop();
                for(int i=0 ; i<(int)arra[a].size() ; i++){
                    b = arra[a][i];
                    if(vis[b]==-1){
                        vis[b] = 1 - vis[a];
                        if(!vis[b])c++;
                        else c1++;
                        q.push(b);
                    }
                    else if(vis[a] == vis[b]){
                        flag = false;
                        break;
                    }}
            }
            ans += ((c<c1 and c!=0) or c1==0)?c:c1;
        }
        if(!flag)printf("-1\n");
        else if(m==0)printf("%d\n",n);
        else printf("%d\n",ans);
        for(int i=0 ; i<n ; i++)arra[i].clear();
    }

    return 0;
}
