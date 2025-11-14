class Solution {
  public:
  
    void canVisit(int i,int j,vector<string> &res,string ans,vector<vector<int>> maze,vector<vector<int>>& vis){
        // if we reach the destination from any path, push that path in the answer
        if(i==maze.size()-1 && j==maze.size()-1){
            res.push_back(ans);
            return;
        }

        //Check if we can visit the cell below the current cell
        if(i+1<maze.size() && !vis[i+1][j] && maze[i+1][j]){
            vis[i][j]=1;
            canVisit(i+1,j,res,ans + 'D',maze,vis);
            vis[i][j]=0;
        }
        
        //Check if we can visit the left cell
        if(j-1>=0 && !vis[i][j-1] && maze[i][j-1]){
            vis[i][j]=1;
            canVisit(i,j-1,res,ans+'L',maze,vis);
            vis[i][j]=0;
        }
        
        //Check if we can visit the right cell
        if(j+1<maze.size() && !vis[i][j+1] && maze[i][j+1]){
            vis[i][j]=1;
            canVisit(i,j+1,res,ans+'R',maze,vis);
            vis[i][j]=0;
        }
        
        //Check if we can visit the cell above the current cell
        if(i-1>=0 && !vis[i-1][j] && maze[i-1][j]){
            vis[i][j]=1;
            canVisit(i-1,j,res,ans+'U',maze,vis);
            vis[i][j]=0;
        }
    }    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n=maze.size();
        vector<string> res;
        vector<vector<int>> vis(n,vector<int>(n,0));
        string ans;
        //Calls the function only if the maze[0][0] is 1
        if(maze[0][0])
            canVisit(0,0,res,ans,maze,vis);
        return res;
    }
};