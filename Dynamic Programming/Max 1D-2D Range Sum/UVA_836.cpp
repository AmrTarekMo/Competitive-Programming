#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long
#define ii pair<int,int>

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t,v=0;
    cin>>t;
    while(v++<t){
        if(v!=1)cout<<endl;
        string kelma;
        cin>>kelma;
        int n = kelma.size();
        int arra[n][n],temp[n];
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++)
                if(kelma[j]=='1')arra[i][j] = 1;else arra[i][j] = -1e7;
            if(i+1 == n)break;
            cin>>kelma;
        }
        ll maxx = -1e9;
        for(int i=0 ; i<n ; i++){
            memset(temp,0,sizeof(temp));
            for(int j=i ; j<n ; j++){
                for(int k=0 ; k<n ; k++)
                    temp[k] += arra[k][j];
                ll maxcur = 0;
                for(int k=0 ; k<n ; k++){
                    maxcur += temp[k];
                    maxx = max(maxx, maxcur);
                    if(maxcur < 0)maxcur = 0;
                }
            }
        }
        cout<<max(maxx,(ll) 0)<<endl;
    }
    return 0;
}

