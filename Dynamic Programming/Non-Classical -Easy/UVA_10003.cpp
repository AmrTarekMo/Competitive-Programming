#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long
#define ii pair<int,int>

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};

int n,l,arra[55],memo[55][55];
int solve(int sta,int end){
    if( sta+1 == end)return 0;

    if(memo[sta][end] != -1)return memo[sta][end];
    int ans=1e9;
    for(int i=sta+1 ; i<end ; i++)
        ans = min(ans , solve(sta,i)+solve(i,end)+(arra[end]-arra[sta]));
    return memo[sta][end] = ans;
}

int main()
{
    while(scanf("%d",&l) and l and scanf("%d",&n) ){
        memset(memo,-1,sizeof(memo));
        for(int i=1 ; i<=n ; i++)
            scanf("%d",arra+i);
        arra[0] = 0;arra[n+1] = l;
        int a = solve(0,n+1);
        printf("The minimum cutting is %d.\n",a);
    }

    return 0;
}
