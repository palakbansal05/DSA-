#include <bits/stdc++.h>
using namespace std;

class CoinChange {
public:
    int coinChange(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (i == 0) {
                    dp[i][j] = INT_MAX - 1;
                }
            }
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < sum + 1; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = min(1 + dp[i][j - arr[i - 1]], dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return (dp[n][sum] == INT_MAX - 1) ? -1 : dp[n][sum];
    }
};

int main() {

}
