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
    ll n,m;
    while(cin>>n>>m and n+m!=0){
        ll arra[n][m] , vec[n];
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<m ; j++){
                cin>>arra[i][j];
                arra[i][j] = arra[i][j]==0?1:-1e7;
            }
        ll sum = 0 , maxx = 0 , ans = 0;
        for(int i=0 ; i<m ; i++){
            memset(vec,0,sizeof(vec));
            for(int j = i; j<m ; j++){
                for(int k = 0 ; k<n ; k++)
                    vec[k] += arra[k][j];
                sum = maxx = 0;
                for(int k = 0 ; k<n ; k++){
                    sum += vec[k];
                    maxx = max(maxx, sum);
                    if(sum < 0 )sum = 0;
                }
                ans = max(maxx ,ans);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}

