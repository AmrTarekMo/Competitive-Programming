#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long
#define ii pair<int,int>

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};

int memo[14][104],m,n,arra[14][104];
int solve(int i , int j){
    if(j == n)return 0;
    if(memo[i][j] != 1e9)
        return memo[i][j];

    int ans = 1e9, a ;
    for(int k=-1 ; k<2 ; k++){
        if(i+k < 0)a = m-1 ;
        else if(i+k >= m)a = 0 ;
        else a = i+k;
        ans = min(ans, solve(a,j+1)+arra[i][j]);
    }
    return memo[i][j] = ans ;
}
void output(int i , int j){
    if(j==n)return;
    int a=i-1 , c = i+1;
    if(a<0)a = m-1 ; if(c>=m)c = 0;

    ii num[3] ;
    num[0].F = memo[a][j] ; num[0].S = a;
    num[1].F = memo[i][j] ; num[1].S = i;
    num[2].F = memo[c][j] ; num[2].S = c;
    sort(num,num+3);
    cout<<num[0].S+1<<" \n"[j+1==n];
    output(num[0].S,j+1);
}

int main()
{
    while(scanf("%d%d",&m,&n) !=EOF){
        for(int i=0 ; i<m ; ++i)
            for(int j=0 ; j<n ; ++j)
                cin>>arra[i][j],memo[i][j] = 1e9;

        for(int i=0 ; i<m ; i++)
            solve(i,0);
        int minn = 1e9, pos;
        for(int i=0 ; i<m ; i++)
            if(memo[i][0] < minn)
                pos = i , minn = memo[i][0];
        output(pos,0);
        cout<<minn<<endl;
    }

    return 0;
}
