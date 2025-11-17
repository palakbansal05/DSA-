#include <bits/stdc++.h>
using namespace std;

class MinimumPlatforms {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0, j = 0, c = 0;
        int ans = 0;

        while (i < arr.size() && j < dep.size()) {
            if (arr[i] <= dep[j]) {
                i++;
                c++;
            } else {
                c--;
                j++;
            }
            ans = max(c, ans);
        }
        return ans;
    }
};

int main() {

}
