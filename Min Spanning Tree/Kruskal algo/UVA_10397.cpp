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
double car(int a,int b,int c,int d){
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

int main()
{
    int n,k;
    while(scanf("%d",&n)!=EOF){
        int arra[n][2],a,b;
        double mst=0;
        vector<pair<double,ii>>edge;
        for(int i=0 ; i<n ; i++)
            scanf("%d%d",&arra[i][0],&arra[i][1]);

        for(int i=0 ; i<n ; i++)
            for(int j=i+1 ; j<n ; j++)
                edge.push_back({car(arra[i][0],arra[i][1],arra[j][0],arra[j][1]),{i+1,j+1}});
        sort(edge.begin() , edge.end());
        UnionFind tree(n+1);
        scanf("%d",&k);
        for(int i=0 ; i<k ; i++){
            scanf("%d%d",&a,&b);
            tree.union_set(a,b);
        }
        for(int i=0 ; i<(int)edge.size() ; i++){
            a = edge[i].S.F;
            b = edge[i].S.S;
            if(!tree.same_set(a,b)){
                tree.union_set(a,b);
                mst += edge[i].F;
            }
        }
        cout<<fixed<<setprecision(2)<<mst<<endl;
    }
    return 0;
}
