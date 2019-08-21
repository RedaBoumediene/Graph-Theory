/********************************************
Detect if their is a cycle in directed graph
                    Idea :
using 0 for !visited
using 1 for curr dfs
using 2 for visited
********************************************/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
const int N = 1e5;
int n,m,ans=0;
int vis[N];
bool flag = false;

void dfs(int u){
    if(vis[u]==1){
        flag = true;
        return;
    }

    if(vis[u]==2)
        return;

    vis[u]=1;

    for(int i=0;i<g[u].size();i++)
            dfs(g[u][i]);

    vis[u]=2;
}



int main(){
    cin>>n>>m;
    g.clear();
    g.resize(n);
    for(int a,b,i=0;i<m;i++){
        cin>>a>>b;
        g[a].push_back(b);
    }

    for(int i=0;i<n;i++){
        if(!vis[i])
            dfs(i);
    }
    cout<<((flag)?"YES":"NO");

    return 0;
}
