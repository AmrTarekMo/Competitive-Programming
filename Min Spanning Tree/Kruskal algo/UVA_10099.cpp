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
int vis[105]={0},minn=1e9;
vector<vector<int>>arra(105);
map<ii,int>mp;
bool dfs(int i , int z){
    vis[i]=1;
    if(i == z)return true;
    for(int j=0 ; j<arra[i].size() ; j++){
        if(!vis[arra[i][j]])
            if(dfs(arra[i][j],z)){
                minn = min(minn , mp[{i,arra[i][j]}]);
                return true;
            }
    }
    return false;
}

int main()
{
    int n,m,v=0;
    while(++v and scanf("%d%d",&n,&m) and n+m!=0){
        vector<pair<int,ii>>edge;
        int a,b,c,ans;
        for(int i=0 ; i<m ; i++){
            scanf("%d%d%d",&a,&b,&c);
            edge.push_back({c,{a,b}});
            mp[{a,b}] = mp[{b,a}] = c;
            mp[{b,b}] = mp[{a,a}] = 0;
        }
        UnionFind tree(n+1);
        sort(edge.rbegin(),edge.rend());
        for(int i=0 ; i<(int)edge.size() ; i++){
            a = edge[i].S.F;
            b = edge[i].S.S;
            if(!tree.same_set(a,b)){
                tree.union_set(a,b);
                arra[a].push_back(b);
                arra[b].push_back(a);
            }
        }
        scanf("%d%d%d",&a,&b,&c);
        dfs(a,b);
        ans = ceil(c/((minn-1)*1.0));
        printf("Scenario #%d\nMinimum Number of Trips = %d\n\n",v,ans);

        for(int i=0 ; i<105 ; i++)arra[i].clear();
        mp.clear();
        memset(vis,0,sizeof(vis));
        minn=1e9;
    }

    return 0;
}
