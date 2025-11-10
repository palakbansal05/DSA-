//Time Complexity: O(m*n)
// where m is the no. of rows and n is the no. of columns in the matrix
// and m*n is the total no. of element present in the matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix[0].size() - 1;
        int m = matrix.size() - 1;
        int top = 0;
        int right = n;
        int left = 0;
        int bottom = m;
        vector<int> res;
        while(top <= bottom && left <= right){
          
          // Traverse the Matrix from left to right 
            for(int i = left; i <= right; i++){
                res.push_back(matrix[top][i]);
            }
            top++; 

          // Traverse the Matrix from top to bottom 
            for(int i = top; i <= bottom; i++){
                res.push_back(matrix[i][right]);
            }
            right--;
 
            if(top <= bottom){
              // Traverse the Matrix from right to left
                for(int i = right; i >= left; i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left <= right){
              // Traverse the Matrix from bottom to top
                for(int i = bottom; i >= top; i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};
