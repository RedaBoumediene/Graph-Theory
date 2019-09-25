#include<bits/stdc++.h>
using namespace std;
int n,m;
int grid[500][500];
int cost[500][500];

int main(){
    freopen("in","r",stdin);
    cin>>n>>m;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            grid[i][j]=cost[i][j]=((i==j)?0:1e9);

    for(int a,b,c,i=0;i<m;i++){
        cin>>a>>b>>c;
        cost[a][b]=grid[a][b]=min(grid[a][b],c);
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                    if(cost[i][j]>cost[i][k]+cost[k][j]){
                        cost[i][j]=cost[i][k]+cost[k][j];
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<cost[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}
