//Brute Force Solution
//Time Complexity: O(2^(m+n)) where m is the size of string1 and n is the size of the string 2

class Solution {
public:

    int solve(int m,int n,string text1, string text2){
        //if any of the string is empty,then the length of the subsequence won't increase further
        if(m==0|| n==0)
            return 0;
        //if the elements of the strings are same, move ahead in both the strings
        if(text1[m-1]==text2[n-1])
            return 1+solve(m-1,n-1,text1,text2);

        //if the elements of the string are not same, then you have two choices
        else{
            return max(solve(m,n-1,text1,text2), solve(m-1,n,text1,text2));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1.size(),text2.size(),text1,text2);
    }
};

//Better Approach(Memoization)
//Time Complexity: O(m*n)

class Solution {
public:
    int cache[1001][1001];
    int solve(int m,int n,string text1, string text2){
        if(m==0|| n==0)
            return 0;
        if(cache[m][n]!=-1)
            return cache[m][n];

        if(text1[m-1]==text2[n-1])
            return cache[m][n]=1+solve(m-1,n-1,text1,text2);
        else{
            return cache[m][n]=max(solve(m,n-1,text1,text2), solve(m-1,n,text1,text2));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(cache,-1,sizeof(cache));
        return solve(text1.size(),text2.size(),text1,text2);
    }
};

//Optimized Approach
//Time Complexity: O(m*n) where m is the size of the 1st string and
//Space Complexity: O(m*n) n is the size of the 2nd string

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> cache(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int i=1;i<=text1.size();i++){ //length of string 1
            for(int j=1;j<=text2.size();j++){ //length of string 2
                if(i==0||j==0)
                    cache[i][j]=0;
                else if(text1[i-1]==text2[j-1])
                    cache[i][j]=1+cache[i-1][j-1];
                else
                    cache[i][j]=max(cache[i][j-1],cache[i-1][j]);
            }
        }
        return cache[text1.size()][text2.size()];
    }
};
