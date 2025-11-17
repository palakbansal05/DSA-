#include <bits/stdc++.h>
using namespace std;

class Permutations {
private:
    int factorial(int n) {
        int f = 1;
        for (int i = 2; i <= n; i++) f *= i;
        return f;
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        int total = 1;
        for (int i = 2; i <= n; i++) total *= i; // n!

        vector<vector<int>> result;

        for (int k = 0; k < total; k++) {
            int temp = k;
            vector<int> tempList;
            vector<int> numbers(nums.begin(), nums.end());

            for (int i = n; i >= 1; i--) {
                int fact = factorial(i - 1);
                int index = temp / fact;
                tempList.push_back(numbers[index]);
                numbers.erase(numbers.begin() + index);
                temp %= fact;
            }

            result.push_back(tempList);
        }

        return result;
    }
};
