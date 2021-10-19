#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	
	void dfs(list<int> lst[],vector<bool> &vis,int src)
	{
	    vis[src]=true;
	    for(auto x : lst[src])
	    {
	        if(!vis[x])
	        {
	            dfs(lst,vis,x);
	        }
	    }
	}
	
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        list<int> lst[V];
        for(int i=0;i<V;i++)
        {
            for(auto x : adj[i])
            {
                lst[i].push_back(x);
            }
        }
        lst[c].remove(d);
        lst[d].remove(c);
        vector<bool> vis(V,false);
        dfs(lst,vis,c);
        if(!vis[d])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
