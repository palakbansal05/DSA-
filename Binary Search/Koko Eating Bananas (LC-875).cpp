class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        for(int ele:piles){
            if(ele>maxi)
                maxi=ele;
        }
        int high=maxi;
        int low=1;
        while(low<high){
            int mid=low+(high-low)/2;
            int currh=0;
            for(int ele:piles)
                currh+=ceil((ele*1.0)/(mid*1.0));
            if(currh<=h)
                high=mid;
            else if(currh>h)
                low=mid+1;
        }
        return low; 
    }
};