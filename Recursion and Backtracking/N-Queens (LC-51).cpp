//Brute Force Solution

class Solution {
public:
    bool safe(int row,int col,int n,vector<string> board){

        int duprow=row;
        int dupcol=col;
        for(int i=0;i<col;i++){
            if(board[row][i]=='Q')
                return false;
        }

        while(duprow>=0 && dupcol>=0){
            if(board[duprow][dupcol]=='Q')
                return false;
            duprow--;
            dupcol--;
        }

        duprow=row;
        dupcol=col;

        while(duprow<n && dupcol>=0){
            if(board[duprow][dupcol]=='Q')
                return false;
            duprow++;
            dupcol--;
        }
        return true;
    }
    void solve(int n,int col,vector<string> &board, vector<vector<string>> &res){
        if(col==n){
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(safe(row,col,n,board)){
                board[row][col]='Q';
                solve(n,col+1,board,res);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string>board(n);
        vector<vector<string>> res;
        for(int i=0;i<n;i++)
            board[i]=s;
        solve(n,0,board,res);
        return res;
    }
};

//Optimized Approach

class Solution {
public:
    void solve(int n,int col,vector<string> &board, vector<vector<string>> &res, vector<int> &leftrow,vector<int>& lowerdiag, vector<int>& upperdiag){
        if(col==n){
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
           if(leftrow[row]==0 && lowerdiag[row+col]==0 && upperdiag[n-1+row-col]==0){
                leftrow[row]=1;
                lowerdiag[row+col]=1;
                upperdiag[n-1+row-col]=1;
                board[row][col]='Q';
                solve(n,col+1,board,res,leftrow,lowerdiag,upperdiag);
                board[row][col]='.';
                leftrow[row]=0;
                lowerdiag[row+col]=0;
                upperdiag[n-1+row-col]=0;                
           }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string>board(n);
        vector<vector<string>> res;
        for(int i=0;i<n;i++)
            board[i]=s;
        vector<int> leftrow(n,0);
        vector<int> lowerdiag(2*n-1,0);
        vector<int> upperdiag(2*n-1,0);
        solve(n,0,board,res,leftrow,lowerdiag,upperdiag);
        return res;
    }
};