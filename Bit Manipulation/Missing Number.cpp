class MissingNumber {
public:
    int missingNumber(vector<int>& nums) {
        int xor_ = 0;
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            xor_ ^= i;
        }
        for (int num : nums) {
            xor_ ^= num;
        }
        return xor_;
    }
};