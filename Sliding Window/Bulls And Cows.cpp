class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int>arr1(10,0);
        vector<int>arr2(10,0);
        for(int i=0;i<secret.size();i++)
        {
            arr1[secret[i]-'0']++;
        }
        for(int i=0;i<guess.size();i++)
        {
            arr2[guess[i]-'0']++;
        }
        int common=0;
        for(int i=0;i<10;i++)
        {
        common+=min(arr1[i],arr2[i]);
        }

        int correctindex=0;
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
            correctindex++;
        }
        string ans = to_string(correctindex) + "A" + to_string(common - correctindex) + "B";
        return ans;
    }
};