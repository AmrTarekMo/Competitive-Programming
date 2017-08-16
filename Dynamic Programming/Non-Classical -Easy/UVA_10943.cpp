#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long
#define ii pair<int,int>

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};
ll n,k,ans=0,mod=1000000;
ll memo[105][105];
ll solve(ll i , ll rem){
    if(i==1)return 1;
    if(memo[rem][i] != -1)
        return memo[rem][i] % mod;
    ll a=0;
    for(int j=0 ; j<=rem ; j++){
        if(rem-j >=0 )
            a += solve(i-1,rem-j);
    }
    return memo[rem][i] = a % mod;
}
int main()
{
    while(true){
        cin>>n>>k;
        if(n+k==0)break;
        memset(memo,-1,sizeof(memo));
        ans = solve(k,n);
        cout<<ans%mod<<endl;
    }

    return 0;
}
