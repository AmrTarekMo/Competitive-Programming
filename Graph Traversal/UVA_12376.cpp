#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define ll long long

vector<vector<int>> arra(105);
int hold[105],c=-1,ans=0;

void last(int i){
    int maxx=0,pos=-1;
    for(int j=0 ; j<(int)arra[i].size() ; j++)
        if(hold[arra[i][j]] > maxx){
            maxx = hold[arra[i][j]];
            pos = arra[i][j];
        }
    if(pos!=-1) {
        c = pos;
        ans+=maxx;
        last(pos);
    }
    else cout<<ans<<' '<<c<<endl;
}

int main()
{
    int t,v=0;
    cin>>t;
    while(v++ < t){
        int n,m,x,y;
        cin>>n>>m;
        for(int i=0 ; i<n ; i++)
            cin>>hold[i];
        for(int i=0 ; i<m ; i++){
            cin>>x>>y;
            arra[x].push_back(y);
        }
        cout<<"Case "<<v<<": ";
        last(0);
        for(int i=0 ; i<n ; i++)
            arra[i].clear();
        memset(hold,0,sizeof(hold));
        c=-1;
        ans=0;
    }
    return 0;
}
