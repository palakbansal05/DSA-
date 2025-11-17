class Solution {
public:
    bool isPalindrome(string s) {
      string temp="";
      int i=0;
      for(char ch:s){
        if (ch>='a' && ch<='z'){
            temp+=ch;
        }
        else if(ch>='0' && ch<='9'){
            temp+=ch;
        }
        else if(ch>='A' && ch<='Z'){
            temp+=(ch+32);
        }
        else{
            continue;
        }
      } 
      int n=temp.size();
      int left=0,right=n-1;
      while(left<right){
        if(temp[left]==temp[right]){
            left++,right--;
        }
        else{
            return false;
        }
      }
      return true;
    }
};