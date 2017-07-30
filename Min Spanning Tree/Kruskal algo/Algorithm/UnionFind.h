#include <bits/stdc++.h>
using namespace std;

#ifndef UNIONFIND_H
#define UNIONFIND_H

class UnionFind {
private:
    vector<int> parent , rank;
public:
    UnionFind(int n);
    int find_set(int x);
    bool same_set(int x , int y);
    void union_set(int x , int y);
};


#endif
