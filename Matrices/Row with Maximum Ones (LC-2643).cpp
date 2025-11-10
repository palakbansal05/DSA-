//Time Complexity: O(m*n)
// where n is the number of rows in the matrix and m is the number of columns in the matrix
// and m*n is the total number of elements present in the matrix

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> res(2);
        int m=mat.size();
        int n=mat[0].size();
        int maxOnes=0;
      //Traverse over each row
        for(int i=0;i<m;i++){
            int currOnes=0;
      //Traverse over the row to find the total number of ones in that row
            for(int j=0;j<n;j++){
                if(mat[i][j]==1)
                    currOnes++;
            }
      // If the number of ones in the current row is more than the maximum number of ones in any row till now 
      //then add that row to the result and set the current number of ones as the maximum number of ones encountered in any row till now
            if(currOnes>maxOnes){
                res[0]=i;
                res[1]=maxOnes=currOnes;
            }
        }
        return res;
    }
};
