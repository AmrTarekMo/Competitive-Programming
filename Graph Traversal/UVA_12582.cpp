#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define ll long long

int main()
{
    int t,v=0;
    cin>>t;
    while(v++ < t){
        string kelma;
        cin>>kelma;
        stack<char> s;
        int vis[28]={0};

        s.push(kelma[0]);
        for(int i=1 ; i<kelma.size() ; i++){
            if(kelma[i]!= s.top()){
                vis[s.top()-'A']++;
                vis[kelma[i]-'A']++;
                s.push(kelma[i]);
            }
            else s.pop();
        }
        printf("Case %d\n",v);
        for(int i=0 ; i<27 ; i++)
            if(vis[i]>0)
                cout<<char(i+'A')<<" = "<<vis[i]<<endl;
    }
    return 0;
}
