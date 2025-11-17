 int countPrimes(int n) {
        vector<bool> vis(n);
        if (n < 2) {
            return 0;
        }
        vis[0] = true;
        vis[1] = true;
        int c = 0;
        for (int i = 2; i < n; i++) {
            if (!vis[i]) {
                c++;
                for (int j = 1; j * i < n; j++) {
                    vis[j * i] = true;
                }
            }
        }
        return c;
    }