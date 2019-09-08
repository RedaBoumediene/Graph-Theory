#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int> > g;
vector<int> indx,low;
vector<pair<int,int> > bridges ;
vector<bool> art;
int dfsTime,child;

void dfs(int u,int p){
    indx[u]=low[u]=++dfsTime;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(indx[v]==0){
            if(p==-1)
                child++;
            dfs(v,u);
            low[u]=min(low[v],low[u]);
            if(low[v]>indx[u]){
                bridges.push_back(make_pair(u,v));
            }
            if(low[v]>=indx[u])
                art[u]=true;
        }
        else
            if(v!=p){
                low[u]=min(low[u],indx[v]);
            }
    }
}

int main(){

    cin>>n>>m;
    g.clear();
    g.resize(n);
    indx.resize(n);
    low.resize(n);
    art.resize(n);

    for(int a,b,i=0;i<m;i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0,-1);
    art[0]=(child>1);

    cout<<"Bridges are : "<<endl;
    for(int i=0;i<bridges.size();i++)
        cout<<bridges[i].first<<'-'<<bridges[i].second<<endl;

    cout<<endl;

    cout<<"Articulation point are : "<<endl;
    for(int i=0;i<art.size();i++)
        if(art[i])
            cout<<i<<' ';


    return 0;
}
