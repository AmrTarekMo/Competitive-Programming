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
double car(int a , int b ,int c , int d){
    return(sqrt((a-c)*(a-c)+(b-d)*(b-d)));
}

int main()
{
    int t,n,r,x,y,v=0;
    scanf("%d",&t);
    while(v++<t and scanf("%d %d",&n,&r)){
        vector<ii>arra(n);
        vector<pair<double,ii>>edge , bridge;
        double k,mst=0,c=0;
        int a,b,f=n;
        for(int i=0 ; i<n ; i++)
            scanf("%d%d",&arra[i].F,&arra[i].S);

        for(int i=0 ; i<n ; i++)
            for(int j=i+1 ; j<n ; j++){
                k = car(arra[i].F,arra[i].S,arra[j].F,arra[j].S);
                if(k <= r)edge.push_back({k,{i,j}});
                else bridge.push_back({k,{i,j}});
            }
        UnionFind tree(n);
        sort(edge.begin() , edge.end());
        sort(bridge.begin() , bridge.end());
        for(int i=0 ; i<(int)edge.size() ; i++){
            a = edge[i].S.F;
            b = edge[i].S.S;
            if(!tree.same_set(a,b)){
                tree.union_set(a,b);
                c += edge[i].F;
                f--;
            }
        }
        for(int i=0 ; i<(int)bridge.size() ; i++){
            a = bridge[i].S.F;
            b = bridge[i].S.S;
            if(!tree.same_set(a,b)){
                tree.union_set(a,b);
                mst += bridge[i].F;
            }
        }
        printf("Case #%d: ",v);
        cout<<f<<' '<<round(c)<<' '<<round(mst)<<endl;
    }
    return 0;
}
