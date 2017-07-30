#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long
int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};

int vis[27]={0},ca[27]={0},n=0,out[27]={0};
vector<vector<int>>arra(27);
string kelma="";
vector<string>ans;
void dfs(){
    if(kelma.size() == n){
        reverse(kelma.begin(),kelma.end());
        ans.push_back(kelma);
        reverse(kelma.begin(),kelma.end());
        return;
    }
    for(int j=0 ; j<26 ; j++)
        if(ca[j] and !out[j] and !vis[j]){
            vis[j]=1;
            kelma+=(char)(j+'a');
            for(int k=0 ; k<(int)arra[j].size() ; k++)
                out[arra[j][k]]--;
            dfs();
            vis[j]--;
            kelma.pop_back();
            for(int k=0 ; k<(int)arra[j].size() ; k++)
                out[arra[j][k]]++;
        }
}

int main()
{
    char c,c1;
    string s;
    int a=0;
    while(scanf("%c",&c)!=EOF){
        if(a!=0)cout<<endl;
        ca[c-'a']++;
        while(scanf("%c",&c) and c!='\n')if(c!=' ')ca[c-'a']++;
        for(int i=0 ; i<27 ; i++)
            if(ca[i])n++;
        getline(cin,s);
        for(int i=0 ; i<s.size() ; i+=4){
            arra[s[i+2]-'a'].push_back(s[i]-'a');
            out[s[i]-'a']++;
        }
        dfs();
        sort(ans.begin(),ans.end());
        for(int i=0 ; i<ans.size() ; i++)
            cout<<ans[i]<<endl;
        a++;
        ans.clear();
        for(int i=0 ; i<27 ; i++)
            arra[i].clear();
        memset(vis,0,sizeof(vis));
        memset(ca,0,sizeof(ca));
        memset(out,0,sizeof(out));
        n=0;
    }
    return 0;
}
