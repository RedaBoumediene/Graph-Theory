#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<pair<int,int> > >g;
int cost[100007], p[100007];
void dij(int s){
    for(int i=0;i<n;i++)
        cost[i]=1e9;
    cost[s]=0;
    for(int i=0;i<n;i++)
        p[i]=i;
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,s));

    while(!pq.empty()){
        int u=pq.top().second , cst=-pq.top().first;
        pq.pop();
        if(cost[u]<cst)
            continue;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i].first , c=g[u][i].second;
            if(cost[v]>cst+c){
                cost[v]=cst+c;
                p[v]=u;
                pq.push(make_pair(-cost[v],v));
            }
        }
    }
}

int main(){
    cin>>n>>m;
    g.clear();
    g.resize(n);

    for(int a,b,c,i=0;i<m;i++){
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b,c));
        g[b].push_back(make_pair(a,c));
    }

    int s,e;cin>>s>>e;
    dij(s);
    cout<<cost[e]<<endl;
    stack<int> ans;
    ans.push(e);
    while(p[e]!=e){
        ans.push(p[e]);
        e=p[e];
    }
    while(!ans.empty()){
        cout<<ans.top()<<' ';
        ans.pop();
    }
}
