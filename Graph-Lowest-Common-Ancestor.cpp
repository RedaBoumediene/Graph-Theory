#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+3;
int up[N][17],dpth[N];
vector<int> tr[N];
int n;

void fill(int u=1,int p=0){
    dpth[u]=dpth[p]+1;
    up[u][0]=p;
    int k=1;
    while(k<17){
        up[u][k]=up[up[u][k-1]][k-1];
        k++;
    }
    for(int i=0;i<tr[u].size();i++){
        if(tr[u][i]==p)
            continue;
            fill(tr[u][i],u);
    }
}
int ans(int u,int d){
    for(int i=16;i>=0;i--){
        if(d>>i & 1){
            u=up[u][i];
        }
    }
    return u;
}
int lca(int a,int b){
    if(dpth[a]<dpth[b])
        swap(a,b);
    a=ans(a,dpth[a]-dpth[b]);
    if(a==b)
        return a;
    for(int i=16;i>=0;--i){
        if(up[a][i]!=up[b][i])
            a=up[a][i],b=up[b][i];
    }
    return up[a][0];
}
int main(){
    //freopen("in","r",stdin);
    cin>>n;
    for(int a,b,i=0;i<n-1;i++){
        cin>>a>>b;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }
    fill();
    int q;cin>>q;
    while(q--){
        int u,d;cin>>u>>d;
        cout<<lca(u,d)<<endl;
    }

    return 0;
}
