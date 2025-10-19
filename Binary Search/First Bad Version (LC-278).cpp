class Solution {
public:
    int firstBadVersion(int n) {
        int low=1;
        int high=n;
        while(low<high){
            int mid=low+(high-low)/2;
// If the current version is bad version then either the current version or any version before it will be the first bad version
            if(isBadVersion(mid)){
                high=mid;
            }
// If the current version is not a bad version then any version after it will be the first bad version
            else{
                low=mid+1;
            }
        }
        return high;
    }
};
