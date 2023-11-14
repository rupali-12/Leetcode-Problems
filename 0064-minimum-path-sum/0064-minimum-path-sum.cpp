class Solution {
public:
    int solveRec(vector<vector<int>>& grid, int startRow, int startCol){
        if(startRow==0 && startCol==0){
            return grid[startRow][startCol];
        }
        if(startRow<0 || startCol<0) return 1e9;
        
        int up= grid[startRow][startCol] + solveRec(grid, startRow-1, startCol);
        int left = grid[startRow][startCol] + solveRec(grid, startRow, startCol-1);
        return min(up, left);
    }
     int solveMem(vector<vector<int>>& grid, int startRow, int startCol, vector<vector<int>>&dp){
        if(startRow==0 && startCol==0){
            return grid[startRow][startCol];
        }
        if(startRow<0 || startCol<0) return 1e9;
         if(dp[startRow][startCol]!=-1){
             return dp[startRow][startCol];
         }
        
        int up= grid[startRow][startCol] + solveMem(grid, startRow-1, startCol, dp);
        int left = grid[startRow][startCol] + solveMem(grid, startRow, startCol-1, dp);
        return  dp[startRow][startCol]= min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
         int m=grid.size(), n= grid[0].size(); 
     
        // // Approach-1: Recursion 
        // int startRow= m-1, startCol=n-1;
        // return solveRec(grid, startRow, startCol);
        
         // Approach-2: Recursion + Memoization
        int startRow= m-1, startCol=n-1;
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solveMem(grid, startRow, startCol, dp);
    }
};