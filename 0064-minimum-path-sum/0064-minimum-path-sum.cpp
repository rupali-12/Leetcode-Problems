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
    int solveTab(vector<vector<int>>& grid,int m, int n){
        vector<vector<int>>dp(m, vector<int>(n+1, 0)); 
        
        for(int srow=0; srow<m; srow++){
            for(int scol=0; scol<n; scol++){
                if(srow==0 && scol==0){
                    dp[srow][scol] =grid[srow][scol];
                }
                else{
                    int up=1e9, left=1e9;
            if(srow>0){
                up= grid[srow][scol] + dp[srow-1][scol];
            }
            if(scol>0){
                left= grid[srow][scol] + dp[srow][scol-1];
            }
            dp[srow][scol]= min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
    int solveTabSpOpt(vector<vector<int>>& grid,int m,int n){
        vector<int>prev(n,0);
        vector<int>curr(n,0);
        
        for(int row=0; row<m;row++){
            for(int col=0; col<n;col++){
                if(row==0 && col==0){
                    curr[row]= grid[row][col];
                }
                else{
                    int up=1e9, left=1e9;
                    if(row>0){
                        up= grid[row][col] + prev[col];
                    }
                    if(col>0){
                        left= grid[row][col]+curr[col-1];
                    }
                    curr[col]= min(up,left);
                }
            }
            prev= curr;
        }
        return prev[n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
         int m=grid.size(), n= grid[0].size(); 
     
        // // Approach-1: Recursion 
        // int startRow= m-1, startCol=n-1;
        // return solveRec(grid, startRow, startCol);
        
        //  // Approach-2: Recursion + Memoization
        // int startRow= m-1, startCol=n-1;
        // vector<vector<int>>dp(m, vector<int>(n, -1));
        // return solveMem(grid, startRow, startCol, dp);
        
        // // Approach-3: Tabulation
        // return solveTab(grid,m, n);
        
       // Approach-4: Tabulation +space optimization
        return solveTabSpOpt(grid,m, n);
    }
};