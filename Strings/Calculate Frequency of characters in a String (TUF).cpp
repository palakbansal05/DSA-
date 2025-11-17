class Solution{
public:
    void calculateFrequency(string s){
        vector<int> freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i])
                cout<<char(i+'a')<<freq[i]<<" ";
        }
    }
};