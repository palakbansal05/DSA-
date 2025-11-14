//Brute Force Solution
//Time Complexity: O(2^n) where n is the size of the input array

class Solution {
public:
    void solve(vector<int> candidates,vector<int> &arr,vector<vector<int>> &res, int target, int i){
        if(target==0){
            res.push_back(arr);
            return;
        }
        if(i==candidates.size()){
            return;
        }

        //if the current element is less then the target then include that element in the result
        if(candidates[i]<=target){
            arr.push_back(candidates[i]);
            solve(candidates,arr,res,target-candidates[i],i);
            arr.pop_back();
        } 

        //exclude the element from the result (no matter the current element is less than the target or not)
        solve(candidates,arr,res,target,i+1);   
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr;
        vector<vector<int>> res;
        solve(candidates,arr,res,target,0);
        return res;
    }
};