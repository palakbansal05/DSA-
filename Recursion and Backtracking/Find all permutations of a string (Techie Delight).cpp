//Time Complexity: O(n*n!)
//Space Complexity: O(n*n!)+O(n) ---> O(n*n!) where n is the size of the input string
// factorial of n (n!) is the total number of permutations generated

class Solution
{
public:
    void solve(int i,string s,vector<string> &res){
        if(i==s.size()){
            res.push_back(s);
            return;
        }
// Swap the element with all the elements having equal and greater index one by one
// after each swapping, call the solve function to compute the swapped substring from index+1
        for(int j=i;j<s.size();j++){
            swap(s[i],s[j]);
            solve(i+1,s,res);
            swap(s[j],s[i]);
        }
    }
	vector<string> findPermutations(string s){
        vector<string> res;
        if(s.empty())
        	return res;
        solve(0,s,res);
        return res;
    }
};