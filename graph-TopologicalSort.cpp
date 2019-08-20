/***************************************
Topological sort or Topological ordering
       for acyclic directed graph
***************************************/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<int> in,canUse,ans;
int n,m;


int main(){
    cin>>n>>m;
    g.clear();
    g.resize(n);
    in.resize(n);
    for(int a,b,i=0;i<m;i++){
        cin>>a>>b;
        g[a].push_back(b);
        in[b]++;
    }
    for(int i=0;i<n;i++){
        if(in[i] == 0){
            canUse.push_back(i);
        }
    }
    while(!canUse.empty()){
        int u = canUse[canUse.size()-1];
        canUse.pop_back();
        ans.push_back(u);
        for(int i=0;i<g[u].size();i++){
            in[g[u][i]]--;
            if(in[g[u][i]]==0){
                canUse.push_back(g[u][i]);
            }
        }
    }

    if(ans.size() != n){
        puts("Cycle detected !! ");
    }
    else{
        puts("One of Topological ordering possible is :");
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<' ';
        }
    }

    return 0;
}
