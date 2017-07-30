#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define ll long long
int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};

int vis[27]={0},ca[27]={0},n=0,out[27]={0},z=0;
vector<vector<int>>arra(27);
string kelma="";
vector<string> ans;
void dfs(){
    if(kelma.size() == n){
        z++;
        reverse(kelma.begin(),kelma.end());
        ans.push_back(kelma);
        reverse(kelma.begin(),kelma.end());
        return;
    }
    for(int j=0 ; j<26 ; j++)
        if(ca[j] and !out[j] and !vis[j]){
            vis[j]=1;
            kelma+=(j+'A');
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
    cin>>a;
    cin.ignore();
    while(a--){
        scanf("%c",&c);
        while(scanf("%c",&c) and c!='\n')if(c!=' ')ca[c-'A']++;
        for(int i=0 ; i<27 ; i++)
            if(ca[i])n++;
        getline(cin,s);
        for(int i=0 ; i<s.size() ; i+=4){
            arra[s[i+2]-'A'].push_back(s[i]-'A');
            out[s[i]-'A']++;
        }
        dfs();
        if(z==0)cout<<"NO"<<endl;
        else{
            sort(ans.begin(),ans.end());
            for(int i=0 ; i<ans.size() ; i++)
                for(int j=0 ; j<ans[i].size() ; j++)
                    cout<<ans[i][j]<<" \n"[j+1 == ans[i].size()];
        }
        if(a!=0)cout<<endl;

        for(int i=0 ; i<27 ; i++)
            arra[i].clear();
        ans.clear();
        memset(vis,0,sizeof(vis));
        memset(ca,0,sizeof(ca));
        memset(out,0,sizeof(out));
        n=z=0;
    }
    return 0;
}
