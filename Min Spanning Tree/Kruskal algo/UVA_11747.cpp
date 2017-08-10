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
    int n,m;
    while(scanf("%d%d",&n,&m) and (n!=0 or m!=0)){
        vector<pair<int,ii>>edge;
        vector<int>ans;
        int a,b,c;
        for(int i=0 ; i<m ; i++){
            cin>>a>>b>>c;
            edge.push_back({c,{a,b}});
        }
        UnionFind tree(n);
        sort(edge.begin(),edge.end());
        for(int i=0 ; i<(int)edge.size() ; i++){
            a = edge[i].S.F;
            b = edge[i].S.S;
            if(!tree.same_set(a,b))
                tree.union_set(a,b);
            else ans.push_back(edge[i].F);
        }
        if((int)ans.size()==0)cout<<"forest"<<endl;
        else{
            for(int i=0 ; i<(int)ans.size() ; i++)
                cout<<ans[i]<<" \n"[i+1==(int)ans.size()];
        }
    }

    return 0;
}
