// Time Complexity - O(n*m)
// where n is the number of rows and m is the number of columns
// and m*n is the total number of elements in the matrix


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
            for(int i = left; i <= right; i++){
                res.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top; i <= bottom; i++){
                res.push_back(matrix[i][right]);
            }
            right--;

            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};
