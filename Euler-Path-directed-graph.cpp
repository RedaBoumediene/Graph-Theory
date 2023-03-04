//Output any Euler path starting at 1 end ending at n
// Idea : in == out of all vertex except the starting and ending
//		  out of starting must be equal to in of starting + 1 , (inverse of the ending)
//		  ans.size() must be equal to m+1
//		  use stack , pushed continue else add it to the answer 

#include<bits/stdc++.h>
using  namespace  std;
const int MOD = 1e9+7;
const int N = 2e5+7;

int n,m;
int in[N],out[N];
bool vis[N];

vector<pair<int,int>> g[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int u,v,i=0;i<m;i++){
		cin>>u>>v;
		g[u].push_back({v,i});
		out[u]++;
		in[v]++;
	}
	
	int count = 0 , start = -1 , end = -1;
	
	for(int i=1;i<=n;i++){
		if(in[i] == out[i])
			count++;
		else if( in[i]+1 == out[i] )
			start = i;
		else if( in[i] == out[i]+1 )
			end = i;
	}
	
	if(count != n-2 || start != 1 || end != n)
		return cout<<"IMPOSSIBLE"<<endl , 0;
	
	vector<int> ans;
	stack<int> st;
	st.push(start);
	
	while(!st.empty()){
		int u = st.top();
		
		bool pushed = false;
		
		while(g[u].size()>0){
			int child = g[u].back().first;
			int edge = g[u].back().second;
			g[u].pop_back();
			if(vis[edge])
				continue;
			vis[edge] = true;
			st.push(child);
			pushed = true;
			break;
		}
		if(!pushed){
			st.pop();
			ans.push_back(u);
		}
	}

	reverse(ans.begin(),ans.end());
	
	if(ans.size() != m+1)
		cout<<"IMPOSSIBLE"<<endl;
	else
		for(int& e:ans)
			cout<<e<<' ';
	
    return 0;
}

