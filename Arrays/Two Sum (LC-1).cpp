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
