//Brute Force Solution

class Solution {
public:
    void solve(vector<int> candidates,vector<int>&arr,vector<vector<int>> &res,int target,int i){
        if(target==0){
            res.push_back(arr);
            return;
        }
        if(i==candidates.size())
            return;

        //if current element is less than the target,include the element in the result
        if(candidates[i]<=target){
            arr.push_back(candidates[i]);
            solve(candidates,arr,res,target-candidates[i],i+1);
            arr.pop_back();
        }

        // skip the call to include all the elements that are similar to current element 
        //because if we have exclude call for an element we cannot have include call for the same element
        // This is because we do not want duplicate sets.
         int idx=i+1;
         while(idx<candidates.size() && candidates[idx]==candidates[idx-1]){
            idx++;
         }

         //exclude the element from the result
         solve(candidates,arr,res,target,idx);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> arr;
        vector<vector<int>> res;
        solve(candidates,arr,res,target,0);
        return res;
    }
};