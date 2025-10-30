//Time Complexity: O(n)
// where n is the size of the input strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())
            return false;
        unordered_map<char,char> match;
// Check if any element maps to two different elements, if yes return false
        for(int i=0;i<s.size();i++){
            if(match.find(s[i])!=match.end() && match[s[i]]!=t[i])
                return false;
            else
            match[s[i]]=t[i];
        }
// Check if two different characters from s maps to the same character in t, if yes then the size of the set(containing values of hash map) and hashmap will not be same.
        set<char> st;
        for(auto it:match){
            st.insert(it.second);
        }
        if(st.size()!=match.size())
            return false;
        return true;
    }
};
