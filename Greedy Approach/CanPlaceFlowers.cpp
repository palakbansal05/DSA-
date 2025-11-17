#include <bits/stdc++.h>
using namespace std;

class CanPlaceFlowers {
public:
    bool canPlaceFlowers(vector<int>& flower, int n) {
        for(int i = 0; i < flower.size(); i++){
            if(flower[i] == 0 && isSafe(flower, i)){
                flower[i] = 1;
                n--;
            }
        }
        return (n <= 0);
    }

    bool isSafe(vector<int>& arr, int i){
        if((i - 1 >= 0 && arr[i - 1] == 1) || (i + 1 < arr.size() && arr[i + 1] == 1)){
            return false;
        }
        return true;
    }
};

int main() {

}
