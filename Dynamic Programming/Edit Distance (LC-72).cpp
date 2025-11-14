//Brute Force Approach
class Solution {
public:
    int solve(int i,int j, string word1, string word2){
        int m=word1.size();
        int n=word2.size();

        //If the word1 finishes but word2 has some elements left
        //insert those remaining elements of word2 in word1
        if(i==m){
            return n-j; 
        }

        //If the word2 finishes but word1 has some elements left
        //delete those extra elements from word1
        if(j==n){
            return m-i;
        }

        //If the element of the strings are same, move ahead
        if(word1[i]==word2[j])
            return solve(i+1,j+1,word1,word2);

        // If the elements of the strings are different   

        //insert the element of word2 in word1
        int ins=1+ solve(i,j+1,word1,word2);

        //delete the element of word1 
        int del=1+ solve(i+1,j,word1,word2);

        //replace the element of word1 with element of word2
        int rep=1+solve(i+1,j+1,word1,word2);

        return min(rep,min(ins,del));
    }
    int minDistance(string word1, string word2) {
        return solve(0,0,word1,word2);
    }
};

//Better Approach[Memoizeation]

class Solution {
public:
    int cache[501][501];
    int solve(int i,int j, string word1, string word2){
        int m=word1.size();
        int n=word2.size();
        if(i==m){
            return n-j; 
        }
        if(j==n){
            return m-i;
        }

        if(cache[i][j]!=-1)
            return cache[i][j];

        if(word1[i]==word2[j])
            return cache[i][j]=solve(i+1,j+1,word1,word2);

        int ins=1+ solve(i,j+1,word1,word2);
        int del=1+ solve(i+1,j,word1,word2);
        int rep=1+solve(i+1,j+1,word1,word2);
        return cache[i][j]=min(rep,min(ins,del));
    }
    int minDistance(string word1, string word2) {
        memset(cache,-1,sizeof(cache));
        return solve(0,0,word1,word2);
    }
};

//Optimized Approach
//Time Complexity: O(m*n) where m is the length of word1 and n is the length of word2
//Space Complexity: O(m*n)

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> t(word1.size()+1,vector<int>(word2.size()+1));
        for(int i=0;i<=word1.size();i++){ //length of word1
            for(int j=0;j<=word2.size();j++){ //length of word2
                if(i==0)
                    t[i][j]=j;
                else if(j==0)
                    t[i][j]=i;
                else if(word1[i-1]==word2[j-1])
                    t[i][j]=t[i-1][j-1];
                else{
                    t[i][j]=1+ min({t[i-1][j-1],t[i-1][j],t[i][j-1]});
                }
            }
        }
        return t[word1.size()][word2.size()];
    }
};