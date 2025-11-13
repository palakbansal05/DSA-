/*

Given a binary pattern containing '?' wildcard character at a few positions, return all possible combinations of binary strings that can be formed by replacing the wildcard character by either '0' or '1'.

Input: "1?11?00?1?"
Output: {"1011000010", "1011000011", "1011000110", "1011000111", "1011100010", "1011100011", "1011100110", "1011100111", "1111000010", "1111000011", "1111000110", "1111000111", "1111100010", "1111100011", "1111100110", "1111100111"}

*/

class Solution
{
public:
	void solve(int i,string& s, unordered_set<string> &res){
		if(i==s.size()){
			res.insert(s);
			return;
		}
    
    // Replace the question mark once with '0' and once with '1' and then add the question mark again
    //After adding either digit, call the solve function for index + 1
		if(s[i]=='?'){
			s[i]='0';
			solve(i+1,s,res);
			s[i]='1';
			solve(i+1,s,res);
			s[i]='?';
		}
		else{
			solve(i+1,s,res);
		}
	}
	unordered_set<string> findCombinations(string s)
	{
		unordered_set<string> res;
		if(s.empty())
			return res;
		solve(0,s,res);
		return res;
	}
};
