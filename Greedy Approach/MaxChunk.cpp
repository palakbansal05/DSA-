#include <bits/stdc++.h>
using namespace std;

class MaxChunks {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxv = 0;
        int c = 0;
        for (int i = 0; i < arr.size(); i++) {
            maxv = max(maxv, arr[i]);
            if (i == maxv) {
                c++;
            }
        }
        return c;
    }
};

int main() {

}
