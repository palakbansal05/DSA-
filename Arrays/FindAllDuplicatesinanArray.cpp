class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int j=0;j<nums.size();j++)
        {
            mp[nums[j]]++;
        }
        for(auto t: mp)
        {
            if(t.second!=1)
            ans.push_back(t.first);
        }
        return ans;
    }
};
