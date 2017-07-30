#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};
int vis[27]={0},c[27]={0};
vector<vector<int>> arra(27);
vector<string>kelma;
vector<char> topsort;

void dfs(int i){
    vis[i]=1;
    for(int j=0 ; j<(int)arra[i].size() ; j++){
        if(!vis[arra[i][j]])
            dfs(arra[i][j]);
    }
    topsort.push_back(i+'A');
}

int main()
{
    string s;
    while(cin>>s and s[0]!='#'){
        kelma.push_back(s);
        for(int i=0 ; i<s.size() ; i++)
            c[s[i]-'A']++;
    }
    for(int i=0 ; i<kelma.size()-1 ; i++)
        for(int j=0 ; j<min(kelma[i].size(),kelma[i+1].size()) ; j++)
            if(kelma[i][j] != kelma[i+1][j]){
                arra[kelma[i][j]-'A'].push_back(kelma[i+1][j]-'A');
                break;
            }
    for(int i=0 ; i<27 ; i++){
        if(c[i] and !vis[i])
            dfs(i);
    }
    for(int i=topsort.size()-1 ; i>=0 ; i--)
        cout<<topsort[i];
    cout<<endl;

    return 0;
}
