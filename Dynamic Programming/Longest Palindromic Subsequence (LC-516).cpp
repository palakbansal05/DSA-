//Brute Force Approach

class Solution {
public:
    int solve(int i,int j,string &s){
        if(i>j)
            return 0;
        if(i==j)
            return 1;

        if(s[i]==s[j])
            return 2+solve(i+1,j-1,s);
            
        return max(solve(i+1,j,s),solve(i,j-1,s));
    }
    int longestPalindromeSubseq(string s) {
        return solve(0,s.size()-1,s);    
    }
};

//Memoization(Top Down Approach)

class Solution {
public:
    int cache[1001][1001];
    int solve(int i,int j,string &s){
        if(i>j)
            return 0;
        if(i==j)
            return 1;

        if(cache[i][j]!=-1)
            return cache[i][j];
        if(s[i]==s[j])
            return cache[i][j]=2+solve(i+1,j-1,s);
        return cache[i][j]=max(solve(i+1,j,s),solve(i,j-1,s));
    }
    int longestPalindromeSubseq(string s) {
        memset(cache,-1,sizeof(cache));
        return solve(0,s.size()-1,s);    
    }
};

//Tabulation(Bottom Up Approach)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>> cache(1001,vector<int>(1001,-1));
        for(int i=0;i<=s.size();i++){
            for(int j=0;j<=s2.size();j++){
                if(i==0 ||j==0)
                    cache[i][j]=0;
                else if(s[i-1]==s2[j-1])
                    cache[i][j]= 1+cache[i-1][j-1];
                else
                    cache[i][j]=max(cache[i-1][j],cache[i][j-1]);
            }
        }
        return cache[s.size()][s2.size()];   
    }
};