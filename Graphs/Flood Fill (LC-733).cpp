//Time Complexity: O(m*n) where n is the number of rows and m is the number or columns in th input 2D vector
//Space Complexity: O(m*n) (the recursion stack space) 

class Solution {
public:

    void dfs(vector<vector<int>>&image,int sr,int sc, int color, int init){
        int n=image.size();
        int m=image[0].size();
        image[sr][sc]=color;
        if(sr-1>=0 && image[sr-1][sc]==init){
            dfs(image,sr-1,sc,color,init);
        }
        if(sr+1<n && image[sr+1][sc]==init){
            dfs(image,sr+1,sc,color,init);
        }
        if(sc-1>=0 && image[sr][sc-1]==init){
            dfs(image,sr,sc-1,color,init);
        }
        if(sc+1<m && image[sr][sc+1]==init){
            dfs(image,sr,sc+1,color,init);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int init=image[sr][sc];
        if(init==color)
            return image;
        int n=image.size();
        int m=image[0].size();
        dfs(image,sr,sc,color,init);
        return image;
    }
};