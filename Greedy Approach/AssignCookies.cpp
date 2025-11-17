#include <bits/stdc++.h>
using namespace std;

class AssignCookies {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int c = 0;
        vector<bool> check(g.size(), false);
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < g.size(); j++){
                if(s[i] >= g[j] && check[j] == false){
                    c++;
                    check[j] = true;
                    break;
                }
            }
        }
        return c;
    }
};

int main() {

}
