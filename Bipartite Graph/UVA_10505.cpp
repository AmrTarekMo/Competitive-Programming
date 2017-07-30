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
    cin>>t;
    while(t-- and cin>>n){
        for(int i=1 ; i<=n ; i++){
            cin>>m;
            while(m-- and cin>>a){
                if(a>n)continue;
                arra[i].push_back(a);
                arra[a].push_back(i);
            }
        }
        int ans=0;
        memset(vis,-1,sizeof(vis));

        for(int i=1 ; i<=n ; i++){
            if(vis[i] != -1)continue;

            int c1=0,c2=0,flag=true;
            queue<int>q;
            q.push(i);
            vis[i]=0;
            c1++;
            while(!q.empty()){
                a = q.front() ; q.pop();
                for(int j=0 ; j<arra[a].size() ; j++){
                    b = arra[a][j];
                    if(vis[b]==-1){
                        vis[b] = 1 - vis[a];
                        !vis[b]? c1++ : c2++;
                        q.push(b);
                    }
                    else if(vis[a] == vis[b]){
                        flag = false;
                    }}
            }
            if(flag)
                ans+=max(c1,c2);
        }
        cout<<ans<<endl;
        for(int i=0 ; i<=n ; i++)arra[i].clear();
    }

    return 0;
}
