class Solution{
public:
    char maxOccuringCharacter(string &s){
        unordered_map<char,int> freq;
        char res;
        for(char ch:s)
            freq[ch]++;
        int maxFreq=0;
        for(auto it:freq){
            if(it.second>maxFreq){
                maxFreq=it.second;
                res=it.first;
            }
        }
        return res;
    }
};