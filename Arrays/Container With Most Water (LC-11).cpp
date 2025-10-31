//Method 1(Brute Force Solution)
//Time Complexity - O(n^2)
//   where n is the size of the height array

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int currTrappedWater=(j-i)*min(height[i],height[j]);
                if(res<currTrappedWater)
                    res=currTrappedWater;
            }
        }
        return res;
    }
};
