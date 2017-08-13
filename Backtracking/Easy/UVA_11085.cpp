#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long
#define ii pair<int,int>

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};

bool c[10]={0},r[10]={0},d1[20]={0},d2[20]={0},vis[10][10]={0};
int minn=1e9;
void solve(int i , int arra[]){
    if(i==8){
        int ans = 8;
        for(int k=0 ; k<8 ; k++)
            for(int l=0 ; l<8 ; l++)
                if(vis[k][l] and arra[l]==k ){
                    ans--;
                }
        minn = min(minn,ans);
        return ;
    }
    r[i] = true;
    for(int j=0 ; j<8 ; j++)
        if(!c[j] and !d1[j-i+7] and !d2[i+j]){
            c[j] = d1[j-i+7] = d2[i+j] = vis[i][j] = true;
            solve(i+1,arra);
            c[j] = d1[j-i+7] = d2[i+j] = vis[i][j] = false;
        }
}

int main()
{
    int arra[8],v=0;
    while(++v and scanf("%d",arra+0)!=EOF){
        for(int i=1 ; i<8 ; i++){
            scanf("%d",arra+i);
            arra[i]--;
        }
        arra[0]--;
        solve(0,arra);
        printf("Case %d: %d\n",v,minn);
        minn=1e9;
    }

    return 0;
}
