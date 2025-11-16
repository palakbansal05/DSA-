class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        //  code here
        vector<int> freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        int maxFreq=INT_MIN;
        char res;
        for(int i=0;i<26;i++){
            if(freq[i]>maxFreq){
                maxFreq=freq[i];
                res=i+'a';
            }
        }
        return res;
    }
};