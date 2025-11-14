//Brute Force Approach
//Gives MLE

class Solution {
public:
    void solve(int i,int n, int k, vector<int> &ans,vector<vector<int>> &res,vector<int> nums){
        if(ans.size()==k){
            res.push_back(ans);
            return;
        }
        if(i>=n)
            return;
        // include the current element in the result
        ans.push_back(nums[i]);
        solve(i+1,n,k,ans,res,nums);
        ans.pop_back();
        
        //exclude the current element from the result
        solve(i+1,n,k,ans,res,nums);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int> nums;
        vector<int> ans;
        for(int i=0;i<n;i++){
            nums.push_back(i+1);
        }
        solve(0,n,k,ans,res,nums);
        return res;
    }
};