class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<pair<int,int>> temp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    temp.push_back({i,j});
                }
            }
        }
        for(int i=0;i<temp.size();i++){
            int j=temp[i].first;
            int k=temp[i].second;
            for(int l=0;l<n;l++){
                matrix[j][l]=0;
            }
            for(int l=0;l<m;l++){
                matrix[l][k]=0;
            }
        }
    }
};