//Time Complexity: O(n) where n is the size of the input string

class Solution {
public:
    string getHint(string secret, string guess) {
        string res="";
        vector<int> freq1(10,0);
        vector<int> freq2(10,0);
        for(char ele:secret)
            freq1[ele-48]++;
        for(char ele:guess)
            freq2[ele-48]++;
        int x=0;
        int y=0;
        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i])
                x++;
        }
        for(int i=0;i<10;i++){
            y+=min(freq1[i],freq2[i]);
        }
        y=y-x;

        string X=to_string(x);
        string Y=to_string(y);

        return X+"A"+Y+"B";
    }
};