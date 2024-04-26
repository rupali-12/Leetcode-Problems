class Solution {
public:
    int n;
    int dp[201][201];
    int solveRec(int col, int row, vector<vector<int>>&grid){
        if(row==n-1){
           return grid[row][col];
        }
        
        int ans= INT_MAX;
        for(int nextcol= 0; nextcol<n; nextcol++){
            if(nextcol!=col){
                ans= min(ans, solveRec(nextcol, row+1, grid));
            }
        }
        return grid[row][col] + ans;
    }
    
     int solveMem(int col, int row, vector<vector<int>>&grid){
        if(row==n-1){
           return grid[row][col];
        }
         if(dp[row][col]!=-1){
             return dp[row][col];
         }
        
        int ans= INT_MAX;
        for(int nextcol= 0; nextcol<n; nextcol++){
            if(nextcol!=col){
                ans= min(ans, solveRec(nextcol, row+1, grid));
            }
        }
        return dp[row][col] = grid[row][col] + ans;
    }
    
    int solveBottomUp(vector<vector<int>>&grid, vector<vector<int>>&t){
        // t[i][j] = choose jth column in ith row 
       for(int row= n-2; row>=0; row--){
           for(int col=0; col<n; col++){
               int ans= INT_MAX;
               for(int nextcol=0; nextcol<n; nextcol++){
                 if(nextcol!=col){
                     ans= min(ans, t[row+1][nextcol]);
                 }    
               }
               t[row][col]= ans + grid[row][col];
           }
       }    
       int res= INT_MAX;
        for(int i=0; i<n; i++){
            res= min(res, t[0][i]);
        }
        return res;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
         n=grid.size();
        
        // // Approach-1, 2: Recursion + Memoization 
        // memset(dp, -1, sizeof(dp));
        // int result= INT_MAX;
        // for(int col=0; col<n; col++){
        //     // result= min(result, solveRec(col, 0, grid));
        //     result= min(result, solveMem(col, 0, grid));
        // }
        // return result;
        
        // Approach-3: Bottom up 
        vector<vector<int>>t(n, vector<int>(n, INT_MAX));
        for(int col= 0; col<n;col++){
            t[n-1][col] = grid[n-1][col];
        }
        return solveBottomUp(grid, t);
    }
};