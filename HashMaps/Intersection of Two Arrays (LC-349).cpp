class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int m=nums1.size(),n=nums2.size();
        unordered_map<int,int> hash;
        for(int i=0;i<m;i++){
            hash[nums1[i]]=1;
        }

        for(int i=0;i<n;i++){
            if(hash.find(nums2[i])!= hash.end() && hash[nums2[i]] == 1){
                res.push_back(nums2[i]);
                hash[nums2[i]]=0;
            }
        }
        return res;

    }
};