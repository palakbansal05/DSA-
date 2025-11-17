class Subsets {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        int total = 1 << n;

        for (int mask = 0; mask < total; mask++) {
            vector<int> list;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    list.push_back(nums[i]);
                }
            }
            res.push_back(list);
        }
        return res;
    }
};