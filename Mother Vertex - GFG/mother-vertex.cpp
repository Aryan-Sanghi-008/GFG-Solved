//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    void dfs(int i, map<int, bool> &mp, vector<int> &vis, vector<int>adj[])
    {
        vis[i] = 1;
        mp[i] = 1;
        for(auto it : adj[i])
        {
            if(mp.find(it) == mp.end())
            {
                dfs(it, mp, vis, adj);
            }
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<int> vis(V, 0);
	    for(int i = 0; i < V; i++)
	    {
	        map<int, bool> mp;
	        if(!vis[i])
	        {
	            dfs(i, mp, vis, adj);
	        }
	        
	        // condition for the mother vertex
	        if(mp.size() == V)
	        {
	            return i;
	        }
	    }
	    return -1;
	}

};

//{ Driver Code Starts.
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends