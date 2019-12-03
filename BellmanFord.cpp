#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int dist[N], m,n;

vector<vector<pair<int,int> > > g;

void BellmanFord(int s){
    for(int i=0;i<n;i++)
        dist[i]=1e9;
    dist[s]=0;

    for(int k=0;k<n;++k){
        bool flag = true;
        for(int i=0;i<n;i++){
            for(int j=0;j<g[i].size();j++){
                if(dist[g[i][j].first]>dist[i]+g[i][j].second){
                    dist[g[i][j].first] = dist[i]+g[i][j].second ;
                    flag = false;
                }
            }
        }
        if(flag)
            break;
    }

}

int main(){

    cin>>n>>m;
    g.resize(n);
    for(int a,b,c, i=0;i<m;i++){
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b,c));
        //g[b].push_back(make_pair(a,c));
    }
    int x;
    cout<<"Enter the start : "; cin>>x;
    BellmanFord(x);

    for(int i=0;i<n;i++)
        cout<<dist[i]<<" ";

    return 0;
}
