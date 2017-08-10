#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long
#define ii pair<int,int>

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};

class UnionFind {
private:
    vector<int> parent , rank;
public:
    UnionFind(int n){
        rank.assign(n,0);
        parent.assign(n,0);
        for(int i=0 ; i<n ; i++)
            parent[i]=i;
    }
    int find_set(int x){
        if(parent[x] == x)return x;
        return parent[x] = find_set(parent[x]);
    }
    bool same_set(int x , int y){
        return (find_set(x) == find_set(y));
    }
    void union_set(int x , int y){
        if(same_set(x,y))return;
        int a = find_set(x), b = find_set(y);
        if(rank[a] > rank[b])
            parent[b] = a;
        else{
            parent[a] = b;
            if(rank[a] == rank[b])
                rank[b]++;
        }
    }
};
int maxx=0,vis[105]={0};
map<ii,int>mp;
vector<vector<int>>ans(105);
bool dfs(int i , int z){
    vis[i] = 1;
    if(i == z)return true;
    for(int j=0 ; j<(int)ans[i].size() ; j++){
        if(!vis[ans[i][j]])
            if(dfs(ans[i][j],z)){
                maxx = max(maxx , mp[{i,ans[i][j]}]);
                return true;
            }
    }
    return false;
}

int main()
{
    int n,m,k,v=0;
    while(scanf("%d%d%d",&n,&m,&k) and n+m+k!=0 and ++v){
        if(v!=1)cout<<endl;
        vector<pair<int,ii>>edge;
        int a,b,c;
        for(int i=0 ; i<m ; i++){
            cin>>a>>b>>c;
            edge.push_back({c,{a,b}});
            mp[{a,b}]=c;
            mp[{b,a}]=c;
            mp[{a,a}]=0;
            mp[{b,b}]=0;
        }
        UnionFind tree(n+1);
        sort(edge.begin(),edge.end());
        for(int i=0 ; i<(int)edge.size() ; i++){
            a = edge[i].S.F;
            b = edge[i].S.S;
            if(!tree.same_set(a,b)){
                tree.union_set(a,b);
                ans[a].push_back(b);
                ans[b].push_back(a);
            }
        }
        cout<<"Case #"<<v<<endl;
        while(k--){
            cin>>a>>b;
            dfs(a,b);
            if(maxx==0)cout<<"no path"<<endl;
            else cout<<maxx<<endl;
            maxx=0;
            memset(vis,0,sizeof(vis));
        }
        for(int i=0 ; i<105; i++)ans[i].clear();
        mp.clear();
    }

    return 0;
}
