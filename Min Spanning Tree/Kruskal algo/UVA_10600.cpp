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

int solve( int k ,int x , int n , vector< pair< int,ii > >edge ){
    int ans=0,c=0;
    UnionFind tree(n+1);
    for(int i=0 ; i<k ; i++){
        if(i == x)continue;
        int a = edge[i].S.F, b = edge[i].S.S;
        if( !tree.same_set(a,b)){
            ans += edge[i].F;
            tree.union_set(a,b);
            c++;
        }
    }
    if(c == n-1)return ans;
    else return 1e9;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k, mst=0 , minn=1e9;
        cin>>n>>k;
        vector< pair< int,ii > > edge(k);
        vector<int>res;

        for(int i=0 ; i<k ; i++)
            cin >> edge[i].S.F >> edge[i].S.S >> edge[i].F;
        UnionFind tree(n+1);
        sort(edge.begin(),edge.end());

        for(int i=0 ; i<k ; i++){
            int a = edge[i].S.F, b = edge[i].S.S;
            if( !tree.same_set(a,b)){
                res.push_back(i);
                mst += edge[i].F;
                tree.union_set(a,b);
            }
        }
        for(int i=0 ; i<(int)res.size() ; i++)
            minn = min(minn,solve(k,res[i],n,edge));
        printf("%d %d\n",mst,minn);
    }

    return 0;
}
