class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        vector<vector<int>> res(V);
        for(int i=0;i<edges.size();i++){
            res[edges[i].first].push_back(edges[i].second);
            res[edges[i].second].push_back(edges[i].first);
        }
        return res;
    }
};
