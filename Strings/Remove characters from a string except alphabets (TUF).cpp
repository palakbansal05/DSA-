class Solution{
public:
    string onlyCharacterString (string &s){
        string res="";
        for(char ch:s){
            int lower=tolower(ch);
            if(lower>='a' && lower<='z')
                res.push_back(ch);
        }
        return res;
    }
};