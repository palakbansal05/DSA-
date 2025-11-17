class ModularExponentiation {
public:
    int mod = 1337;

    int superPow(int a, vector<int>& b) {
        if (b.size() == 0) {
            return 1;
        }
        int last = b[b.size() - 1];
        vector<int> rest(b.begin(), b.end() - 1);

        int x = find(superPow(a, rest), 10, mod);
        int y = find(a, last, mod);

        return (x * y) % mod;
    }

    int find(int a, int k, int mod) {
        a %= mod;
        int res = 1;
        for (int i = 0; i < k; i++) {
            res = (res * a) % mod;
        }
        return res;
    }
};