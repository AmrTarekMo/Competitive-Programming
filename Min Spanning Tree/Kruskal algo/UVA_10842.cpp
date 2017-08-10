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

int main()
{
    int n,m,t,v=0;
    scanf("%d",&t);
    while(v++<t and scanf("%d%d",&n,&m) ){
        vector<pair<int,ii>>edge;
        int a,b,c,ans=0;
        for(int i=0 ; i<m ; i++){
            scanf("%d%d%d",&a,&b,&c);
            edge.push_back({c,{a,b}});
        }
        UnionFind tree(n);
        sort(edge.rbegin(),edge.rend());
        for(int i=0 ; i<(int)edge.size() ; i++){
            a = edge[i].S.F;
            b = edge[i].S.S;
            if(!tree.same_set(a,b)){
                tree.union_set(a,b);
                ans = edge[i].F;
            }
        }
        printf("Case #%d: %d\n",v,ans);
    }

    return 0;
}
