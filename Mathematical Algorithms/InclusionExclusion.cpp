#include <bits/stdc++.h>
using namespace std;

class InclusionExclusion {
private:
    long gcd(long a, long b) {
        while (b != 0) {
            long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

public:
    int countDivisible(int n, vector<int>& divisors) {
        int m = divisors.size();
        int count = 0;
        for (int mask = 1; mask < (1 << m); mask++) {
            long lcm_val = 1;
            int bits = 0;

            for (int i = 0; i < m; i++) {
                if (mask & (1 << i)) {
                    bits++;
                    lcm_val = lcm(lcm_val, divisors[i]);
                    if (lcm_val > n) break;
                }
            }

            if (lcm_val > n) continue;

            if (bits % 2 == 1) count += n / lcm_val;
            else count -= n / lcm_val;
        }
        return count;
    }
};
