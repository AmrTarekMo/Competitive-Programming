#include "UnionFind.h"
#include <bits/stdc++.h>

using namespace std;

UnionFind :: UnionFind(int n){
    rank.assign(n,0);
    parent.assign(n,0);
    for(int i=0 ; i<n ; i++)
        parent[i]=i;
}
int UnionFind :: find_set(int x){
    if(parent[x] == x)return x;
    return parent[x] = find_set(parent[x]);
}
bool UnionFind :: same_set(int x , int y){
    return (find_set(x) == find_set(y));
}
void UnionFind :: union_set(int x , int y){
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
