class Solution {
public:
    void dfs(vector<vector<int>>&grid,int r,int c,int &max,int &count){
        if(r<0||r>=grid.size()||c<0||c>=grid[0].size()){
            return;
        }
        if(grid[r][c]==0)return;

        grid[r][c]=0;
        count++;
        if(max<count){
            max=count;
        }
        dfs(grid,r-1,c,max,count);
        dfs(grid,r+1,c,max,count);
        dfs(grid,r,c-1,max,count);
        dfs(grid,r,c+1,max,count);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int count=0;
                    dfs(grid,i,j,max,count);
                }
            }
        }
        return max;
    }
};
