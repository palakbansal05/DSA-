class Solution {
  public:
    string removeDuplicates(string &s) {
        // code here
        string res="";
        unordered_set<char> st;
        for(char ch:s){
            if(!st.count(ch)){
                st.insert(ch);
                res.push_back(ch);                
            }
        }
        return res;
    }
};