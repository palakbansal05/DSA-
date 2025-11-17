//Brute Force Approach
//Recursion

class Solution {
public:
    int solve(vector<int> & nums,int i){
        if(i>=nums.size())
        return 0;
        int steal=nums[i]+solve(nums,i+2);
        int skip=solve(nums,i+1);
        return max(steal,skip);
    }
    int rob(vector<int>& nums) {
        return solve(nums,0);
    }
};

//Memoization (Top Down Approach)

class Solution {
public:
    int cache[101];
    int solve(vector<int> & nums,int i){
        if(i<0)
        return 0;
        if(cache[i]!=-1)
            return cache[i];
        int steal=nums[i]+solve(nums,i-2);
        int skip=solve(nums,i-1);
        return cache[i]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        memset (cache,-1,sizeof(cache));
        return solve(nums,nums.size()-1);
    }
};

//Tabulation (Bottom Up Approach)

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> cache(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i==0)
                cache[i]=nums[i];
            else if(i==1)
                cache[i]=max(nums[0],nums[1]);
            else
                cache[i]=max((nums[i]+cache[i-2]),cache[i-1]);
        }
        return cache[nums.size()-1];
    }
};
