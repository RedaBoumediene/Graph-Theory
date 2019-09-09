#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
const int N = 100000;
int n,e,indx[N],low[N],dfsTime;
vector<int> s;
bool vis[N];
int compID[N],cmp=0;

void DFS(int u){
    indx[u] = low[u] = ++dfsTime;
    s.push_back(u);
    vis[u]=true;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(indx[v]==0)
            DFS(v);
        if(vis[v])
            low[u]=min(low[u],low[v]);
    }
    if(indx[u]==low[u]){
        while(true){
            int v=s.back();
            s.pop_back();
            vis[v]=false;
            compID[v]=cmp;
            if(v==u)
                break;
        }
        ++cmp;
    }
}

int main(){

    cin>>n>>e;
    g.clear();
    g.resize(n);

    for(int a,b,i=0;i<e;i++){
        cin>>a>>b;
        g[a].push_back(b);
    }

    for(int i=0;i<n;i++)
        if(indx[i]==0)
            DFS(i);

    cout<<cmp<<endl;

    return 0;
}
