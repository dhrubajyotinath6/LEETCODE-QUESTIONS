//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  public:
  void dfs(int node,int par, vector<int> adj[], vector<int> &vis, vector<int> &ans){
      
      ans.push_back(node);
      vis[node] = 1;
      
      for(auto it : adj[node]){
          
          if(it == par) continue;
          
          if(vis[it] == 0){
              dfs(it, node, adj, vis, ans);
          }
      }
  }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, 0);
        vector<int> ans;
        
        for(int i = 0; i < V; i++){
            if(vis[i] == 0){
                dfs(i, -1, adj, vis, ans);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends