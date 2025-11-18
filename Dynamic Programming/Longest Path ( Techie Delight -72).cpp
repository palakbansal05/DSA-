//Brute Force Solution
//Recursion + Backtracking Approach

class Solution
{
public:
    int maxLen;

    void dfs(const vector<vector<int>> &mat,vector<vector<int>> &vis, int r, int c,int dr, int dc,int len)
    {
        if (r == dr && c == dc){
            maxLen = max(maxLen, len);
            return;
        }

        int m = mat.size();
        int n = mat[0].size();

        vis[r][c] = 1; 

        static int dx[4] = {-1, 1, 0, 0};
        static int dy[4] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++)
        {
            int nr = r + dx[k];
            int nc = c + dy[k];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&!vis[nr][nc] && mat[nr][nc] == 1)
                dfs(mat, vis, nr, nc, dr, dc, len + 1);
        }

        vis[r][c] = 0; // backtrack
    }

    int findLongestPathLen(const vector<vector<int>> &mat,
                           const pair<int, int> &src,
                           const pair<int, int> &dest)
    {
        int sr = src.first;
        int sc = src.second;
        int dr = dest.first;
        int dc = dest.second;

        int m = mat.size();
        int n = mat[0].size();

        if (mat[sr][sc] == 0 || mat[dr][dc] == 0)
            return 0;

        maxLen = 0;

        vector<vector<int>> vis(m, vector<int>(n, 0));

        dfs(mat, vis, sr, sc, dr, dc, 0);

        return maxLen;
    }
};

