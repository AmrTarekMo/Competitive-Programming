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
    int n;
    cin>>n;
    int arra[n][n],temp[n];
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<n ; j++)
            cin>>arra[i][j];
    int maxx = -1e9 , left = -1, right = -1 , up = 0 ,down = 0 ;
    for(int i=0 ; i<n ; i++){
        memset(temp,0,sizeof(temp));
        for(int j=i ; j<n ; j++){
            for(int k=0 ; k<n ; k++)
                temp[k] += arra[k][j];
            int maxcur = 0;
            for(int k=0 ; k<n ; k++){
                maxcur += temp[k];
                if(maxcur < 0){
                    maxcur = 0;
                    up = k+1;
                }
                if(maxcur > maxx){
                    maxx = maxcur;
                    down = k;
                    left = i;
                    right = j;
                }
            }
        }
    }
    cout<<maxx<<endl;

    return 0;
}
