// Time Complexity: O(n +2E) ---> O(n+E) where E is the number of edges in the graph
// Space Complexity: O(n)+O(n)+O(n) ---> O(n) where n is the number of nodes in the graph 

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> res;
        queue<int> q;
        vector<int> vis(adj.size(),0);
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            res.push_back(node);

            //Traverse over all the neighbours of the first element of the queue
            //if they are not already visited, add them to the queue
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return res;
    }
};