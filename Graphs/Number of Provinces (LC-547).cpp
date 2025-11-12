//Brute Force Solution
//Time Complexity: O(n^2) where n is the number of nodes in the graph
//Space Complexity: O(n)

class Solution {
private:
    void dfs(int node, vector<int>&vis, vector<vector<int>> isConnected){
        vis[node]=1; //Mark the node as visited
    
        //Find the neighbors of the current node and if they are not visited, call dfs for them
        //they are the part of the same province so result is not changed
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[node][i] && !vis[i])
                dfs(i,vis,isConnected);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int res=0;
        int n=isConnected.size();
        vector<int>vis(n,0);

        //Traverse over the entire visited array, if any node is not visited
        //this means the node is the part of a new province so add 1 to the result and call the dfs function for the node
        for(int i=0;i<n;i++){
            if(!vis[i]){
                res++;
                dfs(i,vis,isConnected);
            } 
        }
        return res;
    }
};