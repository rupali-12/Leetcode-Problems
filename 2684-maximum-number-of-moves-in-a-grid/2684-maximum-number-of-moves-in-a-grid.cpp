class Solution {
public:
    int m, n;
    vector<vector<int>>dp;
    int solve(int row, int col, vector<vector<int>>& grid){
        if(row<0 || row==m || col==n) return 0;
         if(dp[row][col]!=-1){
             return dp[row][col];
         }
        int maxMoves = 0;
        if(row>0 && col+1<n && grid[row-1][col+1] > grid[row][col]){
            maxMoves = max(maxMoves, 1 + solve(row - 1, col + 1, grid));
        }
        if(col+1<n && grid[row][col+1] > grid[row][col]){
           maxMoves = max(maxMoves, 1 + solve(row, col + 1, grid));
        }
         if(row<m-1 && col+1<n &&  grid[row+1][col+1] > grid[row][col]){
           maxMoves = max(maxMoves, 1 + solve(row + 1, col + 1, grid));
        }
        return dp[row][col] = maxMoves;
        
    }
    int maxMoves(vector<vector<int>>& grid) {
        int mxmoves = 0;
         m= grid.size(), n= grid[0].size();
        dp.resize(m, vector<int>(n, -1));
        
        for(int i=0; i<m; i++){
            int ans= solve(i, 0, grid);
            mxmoves= max(ans, mxmoves);
        }
        
        return mxmoves;
    }
};