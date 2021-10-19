 #include<bits/stdc++.h>
 using namespace std;
 // } Driver Code Ends
class Solution {
public:
	vector<int> bfsOfGraph(int V, vector<int> adj[]){
	    // Code here
	    vector<int> ans;
	    vector<bool> visited(V,false);
	    queue<int> q;
	    int s=0;
	    q.push(s);
	    visited[s]=true;
	    while(!q.empty())
	    {
	        int temp=q.front();
	        q.pop();
	        ans.push_back(temp);
	        for(int i=0;i<adj[temp].size();i++){
	            if(!visited[adj[temp][i]])
	            {
	                q.push(adj[temp][i]);
	               visited[adj[temp][i]]=true;
	            }
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
