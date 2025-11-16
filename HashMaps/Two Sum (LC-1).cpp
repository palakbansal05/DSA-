//Method 1(Optimized):
// Time Complexity: O(n) where n is the size of the input array
// Space Complexity: O(n) (because of the hashmap)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++){
/* If the target-current element present in the map,return the value corresponding to target-currnt element in map and current index
  and if the target-current element is not present in the map, add the current value and its index in the map */
            if(umap.find(target-nums[i])!=umap.end())
                return {umap[target-nums[i]],i};
            umap[nums[i]]=i;
        }
        return{};
    }
};

//Method 2(Brute Force) :
// Time Complexity: O(n^2) where n is the size of the input array
//Space complexity: O(1) 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
// Traverse the array twice to find if any two elements in the input array sum up to create target.
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target)
                    return {i,j};
            }
        }
        return {};
    }
};
