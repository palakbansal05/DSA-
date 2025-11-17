#include <bits/stdc++.h>
using namespace std;

class ActivitySelection {
public:
    int activitySelection(vector<int>& arr, vector<int>& dep) {
        vector<vector<int>> act(arr.size(), vector<int>(2));

        for (int i = 0; i < arr.size(); i++) {
            act[i][0] = arr[i];
            act[i][1] = dep[i];
        }

        sort(act.begin(), act.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int cnt = 1;
        int last = act[0][1];

        for (int i = 1; i < act.size(); i++) {
            if (act[i][0] > last) {
                cnt++;
                last = act[i][1];
            }
        }
        return cnt;
    }
};

int main() {

}
