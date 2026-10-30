class NumMatrix {
public:
    vector<vector<int>>cross;
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        cross = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                cross[i][j]=matrix[i-1][j-1]+cross[i-1][j]+cross[i][j-1]-cross[i-1][j-1];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return cross[row2+1][col2+1]+cross[row1][col1]-cross[row1][col2+1]-cross[row2+1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */