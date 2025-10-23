// This question is given as subset II in geeksforgeeks

class Solution {
public:
    void solve(vector<int> nums, int i, vector<int> &temp,vector<vector<int>> &res){
        if(i>=nums.size()){
            res.push_back(temp);
            return;
        }
// Include the element 
        temp.push_back(nums[i]);
        solve(nums,i+1,temp,res);
        temp.pop_back();
// skip the call to include all the elements that are similar to current element because if we have exclude call for an element we cannot have include call for the same element
// This is because we do not want duplicate sets.
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1])
            idx++;
// Exclude the element
        solve(nums,idx,temp,res);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
// Sort the array so all the same elements come next to each other
        sort(nums.begin(), nums.end());
        solve(nums,0, temp, res);  
        return res;  
    }
};
