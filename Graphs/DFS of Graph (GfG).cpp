// Time Complexity: O(n +2E) ---> O(n+E) where E is the number of edges in the graph
// Space Complexity: O(n)+O(n)+O(n) ---> O(n) where n is the number of nodes in the graph 

class Solution {
  public:
    void dfs(int node,vector<int> &res,vector<int> &vis,vector<vector<int>> adj){
        vis[node]=1;
        res.push_back(node);
        
        //Traverse over all the neighbours of the node
        //if they are not already visited, calls the dfs function for them
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,res,vis,adj);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> vis(adj.size(),0);
        vector<int>res;
        dfs(0,res,vis,adj);
        return res;
    }
};