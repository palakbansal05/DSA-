class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n=matrix.size();
    int m=matrix[0].size();
// Traverse rows of the matrix      
    for(int i=0;i<n;i++){
        int low=0;
        int high=m-1;
// Apply binary search on each row as they are sorted in ascending order
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[i][mid]==target)
                return true;
            else if(matrix[i][mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
    }  
    return false;
    }
};
