#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long
#define ii pair< int,int >
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

int solve(int n, int k, int x, vector<pair<int,ii>> edge){
    int a,b,d=0,mst=0;
    UnionFind tree(n+1);
    for(int i=0 ; i<k ; i++){
        a = edge[i].S.F;
        b = edge[i].S.S;
        if(i==x)continue;
        if(!tree.same_set(a,b)){
            tree.union_set(a,b);
            d++;
            mst += edge[i].F;
        }
    }
    if(d!=n-1)return 1e9;
    else return mst;
}


int main()
{
    int t,v=0;
    scanf("%d",&t);
    while(v++<t){
        int n,k,mst=0,d=0,minn=1e9,a,b,c;
        scanf("%d%d",&n,&k);
        UnionFind tree(n+1);
        vector<pair<int,ii>> edge;
        vector<int>res;
        for(int i=0 ;i<k ; i++){
            scanf("%d%d%d",&a,&b,&c);
            edge.push_back({c,{a,b}});
        }
        sort(edge.begin(),edge.end());

        for(int i=0 ; i<k ; i++){
            a = edge[i].S.F;
            b = edge[i].S.S;
            if(!tree.same_set(a,b)){
                tree.union_set(a,b);
                mst += edge[i].F;
                res.push_back(i);
                d++;
            }
        }
        if(d!=n-1)printf("Case #%d : No way\n",v);
        else{
            for(int i=0 ;i<(int)res.size() ; i++){
                a = solve(n,k,res[i],edge);
                minn = min(minn,a);
            }
            if(minn == 1e9)printf("Case #%d : No second way\n",v);
            else printf("Case #%d : %d\n",v,minn);
        }

    }
    return 0;
}
