
#include <bits/stdc++.h>
using namespace std;

class TopKFreqElement {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        priority_queue<pair<int,int>> pq;   // {freq, key}

        for (auto& it : freqMap) {
            pq.push({it.second, it.first});
        }

        int idx = 0;
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            ans[idx++] = pq.top().second;
            pq.pop();
        }

        return ans;
    }
};

int main() {

}
