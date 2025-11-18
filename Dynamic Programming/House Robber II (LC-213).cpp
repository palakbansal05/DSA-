//Brute Force Approach
//Time Complexity: O(2^n) where n is the size of the input array

class Solution {
public:
    int solve(vector<int>nums,int i,int n){
        if(i>=n)
            return 0;
        int skip=solve(nums,i+1,n);
        int steal=nums[i]+solve(nums,i+2,n);
        return max(skip,steal);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        
        return max(solve(nums,0,n-1),solve(nums,1,n));  
    }
};

//Memoization (Top Down Approach)