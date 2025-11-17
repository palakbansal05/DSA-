class CountSetBits {
public:
    static int countSetBits(int n) {
        if (n <= 0) {
            return 0;
        }
        int x = find(n);
        int a = x * (1 << (x - 1));
        int b = n - (1 << x) + 1;
        return a + b + countSetBits(n - (1 << x));
    }

    static int find(int n) {
        int x = 0;
        while ((1 << x) <= n) {
            x++;
        }
        return x - 1;
    }
};