class Solution {
public:
     int row, col;
    int ans;
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0 || i==row || j==col || grid[i][j]==0){
            ans++;
            return;
        }
        if(grid[i][j]==-1) return;
        
        grid[i][j]=-1;  // avoid overflow
        
         dfs(grid, i-1, j);
         dfs(grid, i+1, j);
         dfs(grid, i, j-1);
         dfs(grid, i, j+1);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
       row = grid.size();
        col= grid[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==1){
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};