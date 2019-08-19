#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
const int N = 1e5;
int n,m;
bool vis[N];

void bfs(int u){
    stack<int> s;
    s.push(u);
    vis[u]=true;
    while(!s.empty()){
        int tp = s.top();
        s.pop();
        cout<<tp<<' ';
        for(int i=0;i<g[tp].size();i++){
            if(!vis[g[tp][i]]){
                vis[g[tp][i]] = true;
                s.push(g[tp][i]);
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


    bfs(1);

    return 0;
}
