class Solution {
public:
    bool isValid(vector<string>&board,int row,int col,int n){

        for(int i=0;i<row;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void NQueens(vector<string>&board,vector<vector<string>>&ans,int row, int n){
        if(row==n){
            ans.push_back(board);
        }
        for(int i=0;i<n;i++){
            if(isValid(board,row,i,n)){
                board[row][i]='Q';
                NQueens(board,ans,row+1,n);
                board[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        NQueens(board,ans,0,n);

        return ans;
    }
};
