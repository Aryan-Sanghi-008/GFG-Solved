//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int v, vector<int> adj[], int x) 
	{
	    queue<int> q;
	    int level = 0;
	    vector<int> vis(v, 0);
	    q.push(0);
	    vis[0] = 1;
	    while(!q.empty())
	    {
	        int si = q.size();
	        for(int i = 0; i < si; i++)
	        {
	            int src = q.front();
	            vis[src] = 1;
	            q.pop();
	            if(src == x)
	            {
	                return level;
	            }
	            for(auto &dest : adj[src])
	            {
	                if(!vis[dest])
	                {
	                    q.push(dest);
	                }
	            }
	        }
	        level++;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends