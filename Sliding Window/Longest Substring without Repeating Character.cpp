class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mxlen=0;
        for(int j=0;j<s.size();j++){
        unordered_map<char,int>mp;
        int len=0;
        for(int i=j;i<s.size();i++)
        {
        mp[s[i]]++;
        if(mp[s[i]]!=1)
        {
            break;
        }
        else
        len++;
        }
            if(len>mxlen)
            mxlen=len;
        }
        return mxlen;
    }
};