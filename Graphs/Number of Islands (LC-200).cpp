//Brute Force Solution
//Time Complexity: O(m*n) where m is the number of rows in the graph 
//Space Complexity: O(m*n) where n is the number of columns in the graph
//m*n is the total number of nodes present in the input grid

class Solution {
public:
    void bfs(int i,int j, vector<vector<char>> grid, vector<vector<int>>& vis){
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        q.push({i,j});
        vis[i][j]=1;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int delrow=-1;delrow<=1;delrow++){
                    int newRow=row+delrow;
                    if(newRow<n && newRow>=0 && grid[newRow][col]=='1' && !vis[newRow][col]){
                        q.push({newRow,col});
                        vis[newRow][col]=1;
                    }
            }
            for(int delcol=-1;delcol<=1;delcol++){
                    int newCol=col+delcol;
                    if(newCol>=0 && newCol<m && grid[row][newCol]=='1' && !vis[row][newCol]){
                        q.push({row,newCol});
                        vis[row][newCol]=1;
                    }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    res++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return res;
    }
};