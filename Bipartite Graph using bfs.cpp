#include<bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
class Solution {
public:

bool isBipartite_util(vector<int> adj[],int src,vector<int> &colour)
{
    queue<int> q;
    q.push(src);
    colour[src]=1;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(auto x : adj[curr])
        {
            if(colour[x]==colour[curr]) //odd cycle
            {
                return false;
            }
            if(colour[x]==-1) //if not coloured
            {
                colour[x]=1-colour[curr];
                q.push(x);
            }
        }
    }
    return true;
}

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> colour(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(colour[i]==-1)
	        {
	            if(!isBipartite_util(adj,i,colour))
	            {
	                return false;
	            }
	        }
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends
