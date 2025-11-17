class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int mxlen=0;
        for(int num : s)
        {
            if(s.find(num-1)==s.end()){
                int length=1;
                while(s.find(num+length) != s.end())
                length++;
                if(length>mxlen)
                mxlen=length;
            }
        }
        return mxlen;
    }
};