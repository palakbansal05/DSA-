//Time Complexity - O(2^n)

class Solution {
public: 
    void solve(vector<int> nums,int i,vector<int> & ans,vector<vector<int>> & res){
        if(i>=nums.size()){
            res.push_back(ans);
            return;
        }
// Include call
        ans.push_back(nums[i]);
        solve(nums,i+1,ans,res);
        ans.pop_back();
// Exclude call
        solve(nums,i+1,ans,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>ans;
        solve(nums,0,ans,res);
        return res;
    }
};
