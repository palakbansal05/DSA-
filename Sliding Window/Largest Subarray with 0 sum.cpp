class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
    int mxlen=0;
    unordered_map<int,int> mp; //sum,index
    int i=0;
    int sum=0;
    mp[0]=-1;
    while(i<arr.size())
    {
        sum+=arr[i];
        if (mp.find(sum) == mp.end()) {
        mp[sum]=i;
        }
        else{
            int index=mp[sum];
            int len=i-index;
            if(mxlen<len)
            mxlen=len;
        }
        i++;
    }
    return mxlen;
    }
};