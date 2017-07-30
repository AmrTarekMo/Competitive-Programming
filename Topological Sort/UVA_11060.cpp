#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long
int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};

int n,m,a,ind[102]={0};
string kelma,kelma1;
vector<vector<int>> arra(102);
map<string,int>mp;
string ans[102];
priority_queue<int> top;
void khan(int b){
    while(!top.empty()){
        a = top.top()*-1;
        top.pop();
        b++;
        cout<<ans[a]<<" ."[b == n];
        for(int j=0 ; j<arra[a].size() ; j++){
            ind[arra[a][j]]--;
            if(!ind[arra[a][j]])
                top.push(-1*arra[a][j]);
        }
    }
}

int main()
{
    int v=0;
    while(scanf("%d",&n)!=EOF and ++v){
        for(int i=0 ; i<n ; i++){
            cin>>kelma;
            mp[kelma]=i;
            ans[i]=kelma;
        }
        scanf("%d",&m);
        for(int i=0 ; i<m ; i++){
            cin>>kelma>>kelma1;
            arra[mp[kelma]].push_back(mp[kelma1]);
            ind[mp[kelma1]]++;
        }
        for(int i=0 ; i<n ; i++)
            if(!ind[i])top.push(-1*i);
        printf("Case #%d: Dilbert should drink beverages in this order: ",v);
        khan(0);
        cout<<"\n\n";
        for(int i=0 ; i<n ; i++)arra[i].clear();
        mp.clear();
        memset(ind,0,sizeof(ind));
    }
    return 0;
}
