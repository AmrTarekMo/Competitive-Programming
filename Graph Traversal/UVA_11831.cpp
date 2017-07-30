#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define ll long long

int main()
{
    int n,m,s;
    while(cin>>n>>m>>s and n!=0 and m!=0 and s!=0){
        int a,b,dn=0,de=0,ds=0,dw=0,ans=0;
        string kelma[n] , hold;
        for(int i=0 ; i<n ; i++)
            cin>>kelma[i];
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<m ; j++){
                if(kelma[i][j]=='N')dn=-1,a=i,b=j;
                else if( kelma[i][j]=='S')ds=1,a=i,b=j;
                else if( kelma[i][j]=='O')dw=-1,a=i,b=j;
                else if( kelma[i][j]=='L')de=1,a=i,b=j;
            }
        cin>>hold;
        for(int i=0 ; i<s ; i++){
            if(hold[i] == 'D'){
                if(dn)dn=0,de=1;
                else if(de)de=0,ds=1;
                else if(ds)ds=0,dw=-1;
                else if(dw)dw=0,dn=-1;
            }
            if(hold[i] == 'E'){
                if(dn)dn=0,dw=-1;
                else if(dw)dw=0,ds=1;
                else if(ds)ds=0,de=1;
                else if(de)de=0,dn=-1;
            }
            if(hold[i] == 'F' and a+dn+ds <n and a+dn+ds>=0 and b+de+dw<m and b+de+dw>=0 and kelma[a+dn+ds][b+de+dw]!='#' ){
                a = a + dn + ds;
                b = b + de + dw;
                if(kelma[a][b]=='*')ans++;
                kelma[a][b]='.';
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
