#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
const int N = 1e5;
int n,m;
bool vis[N];

void dfs1(int u,int p){
    for(int i=0;i<g[u].size();i++){
        if(g[u][i] != p)
            dfs1(g[u][i],u);
    }
}

void dfs2(int u){
    queue<int> q;
    q.push(u);
    vis[u]=true;
    while(!q.empty()){
        int fr = q.front();
        q.pop();
        for(int i=0;i<g[fr].size();i++){
            if(!vis[g[fr][i]]){
                vis[g[fr][i]] = true;
                q.push(g[fr][i]);
            }
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

    //dfs1 or dfs2;

    return 0;
}
