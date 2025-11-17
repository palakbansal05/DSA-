#include <bits/stdc++.h>
using namespace std;

class SlidingWindowMax {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        int idx = 0;

        priority_queue<pair<int,int>> pq; // {value, index}

        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});

            while (pq.top().second <= i - k)
                pq.pop();

            if (i >= k - 1)
                ans[idx++] = pq.top().first;
        }

        return ans;
    }
};

int main() {
    SlidingWindowMax sd;
    vector<int> arr = {1};
    int k = 1;
    vector<int> res = sd.maxSlidingWindow(arr, k);

    for (int x : res) cout << x << " ";
}