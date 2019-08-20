/********************************************
Detect if their is a cycle in directed graph
********************************************/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
const int N = 1e5;
int n,m,ans=0;
bool vis[N];
bool flag = false;

void dfs(int u,int p){
    if(vis[u]){
        flag = true;
        return;
    }
    vis[u]=true;
    for(int i=0;i<g[u].size();i++){
        if(g[u][i]!=p){
            dfs(g[u][i],u);
        }
    }
}



int main(){
    cin>>n>>m;
    g.clear();
    g.resize(n+1);
    for(int a,b,i=0;i<m;i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=0;i<n;i++){
        if(!vis[i])
            dfs(i,-1);
    }
    cout<<((flag)?"YES":"NO");

    return 0;
}
