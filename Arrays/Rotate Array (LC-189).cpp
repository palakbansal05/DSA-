//Method-1

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
// Reverse the starting n-k elements
        reverse(nums.begin(),nums.end()-k);
// Reverse the last k elements
        reverse(nums.end()-k,nums.end());
// Reverse the entire array
        reverse(nums.begin(),nums.end());
    }
};  
