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

    int t;
    cin>>t;
    while(t--){
        int n,k,a,b,c,d;
        cin>>n>>k;
        int arra[n][n],vec[n] ;
        ll ans = 0;
        for(int i=0 ; i<n ; i++)for(int j=0; j<n ; j++)arra[i][j]=1;
        for(int i=0 ; i<k ; i++ ){
            cin>>a>>b>>c>>d;
            a--;b--;c--;d--;
            for(int x = a ; x<=c ; x++)
                for(int z = b ; z<=d ; z++)
                    arra[x][z] = -1e7;
        }
        ll maxx = 0 , sum = 0;
        for(int i=0 ; i<n ; i++){
            memset(vec,0,sizeof(vec));
            for(int j=i ; j<n ; j++){
                for(int k=0 ; k<n ; k++ )
                    vec[k]+=arra[k][j];
                sum = 0 ;
                for(int k=0 ; k<n ; k++){
                    sum += vec[k];
                    maxx = max(maxx , sum);
                    if(sum < 0)sum = 0;
                }
                ans = max(ans , maxx);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}

