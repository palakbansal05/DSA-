//Optimized Approach
//Time Complexity: O(n^2) where n is the number of both rows and columns in the given matrix
//Space Complexity: O(1) 

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
      
      // Find the transpose of the matrix
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
      
      //Reverse every row of the matrix
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
