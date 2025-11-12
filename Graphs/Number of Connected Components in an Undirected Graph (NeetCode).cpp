//Time Complexity: O(n + m) where n is the number of nodes in the graph 
//Space Complexity: O(n + m) and m is the number of edges in the graph

class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<int> &vis){
        vis[node]=1;
        for(int i:adj[node]){
            if(!vis[i])
                dfs(i,adj,vis);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        int res=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                res++;
            }
        }
        return res;
    }
};
