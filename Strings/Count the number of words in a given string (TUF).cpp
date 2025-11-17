class Solution{
public:
    int countWords(string &s){
        int res=1;
        for(char ch:s){
            if(ch==' ')
                res++;
        }
        return res;
    }
};