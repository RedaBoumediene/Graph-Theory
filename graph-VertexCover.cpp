/*********************************************
                Problem :
find minimum number of coloring vertex in black
            of tree Black or White

                condition :
at least one of two adjacent vertex is Black
*********************************************/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
const int N = 1e5;
int n,m,ans=0;
bool vis[N];

bool dfs(int u,int p){
    bool black = false;
    for(int i=0;i<g[u].size();i++){
        if(g[u][i] != p){
            bool curr = dfs(g[u][i],u);
            if(curr)
                black = true;
        }
    }
    if(black)
        ans++;
    return !black;
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
    dfs(0,-1);
    cout<<ans;

    return 0;
}
