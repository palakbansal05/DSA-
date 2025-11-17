#include <bits/stdc++.h>
using namespace std;

class Implementation {
public:
    vector<vector<int>> printGraph(int V, vector<vector<int>>& edges) {
        adjacencyMatrix(V, edges);
        return adjacencyList(V, edges);
    }

    vector<vector<int>> adjacencyMatrix(int V, vector<vector<int>>& edges) {
        vector<vector<int>> mat(V, vector<int>(V, 0));
        for (int i = 0; i < V; i++) {
            mat[i][i] = 1;
        }
        for (auto& p : edges) {
            mat[p[0]][p[1]] = 1;
            mat[p[1]][p[0]] = 1;
        }
        return mat;
    }

    vector<vector<int>> adjacencyList(int V, vector<vector<int>>& edges) {
        vector<vector<int>> list(V);
        for (auto& p : edges) {
            list[p[0]].push_back(p[1]);
            list[p[1]].push_back(p[0]);
        }
        return list;
    }
};
