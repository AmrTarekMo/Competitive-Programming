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
    while(cin>>n and n!=0){
        int arra[n],ans = 0 , maxx = -1;
        for(int i=0 ; i<n ; i++)
            cin>>arra[i];
        for(int i=0 ; i<n ; i++){
            ans += arra[i];
            maxx = max(maxx , ans);
            if(ans < 0)ans = 0 ;
        }
        if(ans > 0)cout<<"The maximum winning streak is "<<maxx<<".\n";
        else cout<<"Losing streak.\n";
    }

    return 0;
}

