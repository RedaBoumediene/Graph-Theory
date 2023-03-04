//Output any Euler cycle starting and ending at 1
// Idea : indeg of all vertex should be even
//		  ans.size() must be equal to m+1
//		  use stack , pushed continue else add it to the answer 

#include<bits/stdc++.h>
using  namespace  std;
const int N = 2e5+7;

int n,m;
int in[N];
bool vis[N];

vector<pair<int,int>> g[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int u,v,i=0;i<m;i++){
		cin>>u>>v;
		in[u]++;
		in[v]++;
		g[u].push_back({v,i});
		g[v].push_back({u,i});
	}
	
	int count = 0;
	for(int i=1;i<=n;i++)
		if(in[i]&1){
			count++;
			break;
		}
			
	if(count)
		return cout<<"IMPOSSIBLE"<<endl , 0;
	
	stack<int> st;
	st.push(1);
	vector<int> ans;
	
	while(!st.empty()){
		int u = st.top();
		
		bool pushed = false;
		
		while(g[u].size()>0){
			int child = g[u].back().first;
			int edge = g[u].back().second;
			g[u].pop_back();
			if(vis[edge])
				continue;
			st.push(child);
			vis[edge] = true;
			pushed = true;
			break;
		}
		if(!pushed){
			st.pop();
			ans.push_back(u);
		}
	}
	
	if(ans.size() != m+1)
		cout<<"IMPOSSIBLE"<<endl;
	else
		for(int& e:ans)
			cout<<e<<' ';
	
	
    return 0;
}

