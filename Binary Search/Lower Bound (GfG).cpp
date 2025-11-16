class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int low = 0, high = arr.size() - 1; 
        int res = arr.size();
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            
            // If middle element >= target, then set res to mid and
            // search in the left half
            if(arr[mid] >= target) {
                res = mid;
                high = mid - 1;
            }
            
            // If middle element < target, then lower bound cannot lie in the before the middle element
            //  so search in the right half
            else {
                low = mid + 1;
            }
        }
        return res;	
    }
};

