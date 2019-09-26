#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n,m;
vector<vector<pair<int,int> > > g;
int p[N];

int find(int u){
    if(p[u]==u)
        return u;
    return p[u]=find(p[u]);
}

vector<pair<int,pair<int,int> > > edges;

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        p[i]=i;
    g.clear();
    g.resize(n);
    for(int a,b,c,i=0;i<m;i++){
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b,c));
        edges.push_back({c,{a,b}});
    }

    sort(edges.begin(),edges.end());

    int ans = 0;

    for(int a,b,i=0;i<edges.size();i++){
        a=edges[i].second.first ; b = edges[i].second.second;
        a = find(a);
        b = find(b);
        if(a!=b){
            ans+=edges[i].first;
            p[a]=b;
        }
    }
    cout<<ans;

    return 0;
}
