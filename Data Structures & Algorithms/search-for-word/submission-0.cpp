class Solution {
public:
    bool solve(int i,int j,vector<vector<char>>& board,string& word,int ind){
        if(i<0||i>=board.size()||j<0||j>=board[0].size()){
            return false;
        }
        if(board[i][j]!=word[ind]){
            return false;
        }
        if(ind==word.length()-1){
            return true;
        }
        char temp=board[i][j];
        board[i][j]='#';

        bool found=
            solve(i+1,j,board,word,ind+1)||
            solve(i-1,j,board,word,ind+1)||
            solve(i,j+1,board,word,ind+1)||
            solve(i,j-1,board,word,ind+1);

        board[i][j]=temp;

        return found;
}    
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(solve(i,j,board,word,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
};
