#include <bits/stdc++.h>
#include "UnionFind.h"
using namespace std;
#define F first
#define S second
#define ll long long
#define ii pair< int,int >
int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};

int main()
{
    int n,k,a,b,c,mst=0;
    scanf("%d%d",&n,&k);
    UnionFind tree(n+1);
    vector< pair<int,ii> > edge;

    for(int i=0 ; i<k ; i++){
        scanf("%d%d%d",&a,&b,&c);  // from , to , weight
        edge.push_back({c,{a,b}})
    }
    sort(edge.begin(),edge.end());
    for(int i=0 ; i<(int)edge.size() ; i++){
        a = edge[i].S.F;
        b = edge[i].S.S;
        if(!tree.same_set(a,b)){
            tree.union_set(a,b);
            mst += edge[i].F;
        }
    }
    printf("%d\n",mst);
    return 0;
}
