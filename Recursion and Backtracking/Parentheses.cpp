#include <bits/stdc++.h>
using namespace std;

class Parenthesis {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> list;
        find(list, "", n, 0, 0);
        return list;
    }

    void find(vector<string>& list, string p, int n, int open, int close) {
        if (open == n && close == n) {
            list.push_back(p);
            return;
        }
        if (open < n) {
            find(list, p + "(", n, open + 1, close);
        }
        if (close < open) {
            find(list, p + ")", n, open, close + 1);
        }
    }
};
