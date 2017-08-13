#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long
int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};

int n,m,sum=0,arra[21],vis[21]={0};
vector<int>ans;
map< vector<int>,int>mp;
void rec(int i){
    for(int j=i ; j<m ; j++){
        if(!vis[j] and sum+arra[j]<=n){
            vis[j]=1;
            sum+=arra[j];
            ans.push_back(arra[j]);
            mp[ans]=sum;
            rec(j+1);
            ans.pop_back();
            vis[j]=0;
            sum-=arra[j];
        }
    }
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        int maxx=0,maxx1=0;
        for(int i=0 ; i<m ; i++)
            scanf("%d",arra+i);
        for(int i=0 ; i<m ; i++){
            rec(i);
            memset(vis,0,sizeof(vis));
            ans.clear();
            sum=0;
        }
        for(map<vector<int>,int> ::iterator it=mp.begin() ; it!=mp.end() ; it++)
            if(maxx1 <= it->S ){
                maxx1 = it->S;
                ans = it->F;
                maxx = (it->F).size();
            }

        for(int i=0 ; i<maxx ;i++)
            cout<<ans[i]<<' ';
        cout<<"sum:"<<maxx1<<endl;
        memset(vis,0,sizeof(vis));
        ans.clear();
        sum=0;
        mp.clear();
    }

    return 0;
}
