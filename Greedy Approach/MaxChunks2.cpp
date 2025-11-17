#include <bits/stdc++.h>
using namespace std;

class MaxChunksII {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stackv;
        for (int num : arr) {
            int maxv = num;
            while (!stackv.empty() && num < stackv.top()) {
                maxv = max(maxv, stackv.top());
                stackv.pop();
            }
            stackv.push(maxv);
        }
        return stackv.size();
    }
};

int main() {

}
