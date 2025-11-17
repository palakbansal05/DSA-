class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int m=mat.size();
        int n=mat[0].size();
        int totalelements=m*n;
        int medianindex=totalelements/2;
        
        int index=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(index==medianindex)
                return mat[i][j];
                index++;
            }
        }
        return 0;
    }
};
