#include <bits/stdc++.h>
using namespace std;

class ArrayPartition {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        int i = 0;
        while(i < nums.size()){
            sum += nums[i];
            i += 2;
        }
        return sum;
    }
};

int main() {
    
}
