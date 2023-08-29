class Solution {
public:
    int solveRec(vector<vector<int>> &grid, int startRow, int startCol){
    if(startRow==0 && startCol==0){
        return grid[startRow][startCol];
    }
    if(startRow<0 || startCol<0){
        return 1e9;
    }
    int up = grid[startRow][startCol] + solveRec(grid, startRow-1,startCol);
    int down = grid[startRow][startCol]+ solveRec(grid, startRow, startCol-1);

//     // 2nd way
//     int up=1e9, down=1e9;
//  if(startRow>0){
//          up = grid[startRow][startCol] + solveRec(grid, startRow-1,startCol);
//  }
//  if(startCol>0){
//      down = grid[startRow][startCol]+ solveRec(grid, startRow, startCol-1);
//  }

    int mxSum = min(up, down);
    return mxSum;
}
int solveMem(vector<vector<int>> &grid, int startRow, int startCol, vector<vector<int>>&dp){
     if(startRow==0 && startCol==0){
        return grid[startRow][startCol];
    }
    if(startRow<0 || startCol<0){
        return 1e9;
    }
    if(dp[startRow][startCol]!=-1){
        return dp[startRow][startCol];
    }
    int up = grid[startRow][startCol] + solveMem(grid, startRow-1,startCol, dp);
    int down = grid[startRow][startCol]+ solveMem(grid, startRow, startCol-1, dp);
     dp[startRow][startCol] = min(up, down);
    return dp[startRow][startCol];
}
int solveTab(vector<vector<int>> &grid){
    int n= grid.size();
    int m= grid[0].size();
    vector<vector<int>>dp(n, vector<int>(m, 0));
    for(int row=0; row<n; row++){
        for(int col= 0; col<m; col++){
            if(row==0 && col==0){
                dp[row][col] = grid[row][col];
            }
           
           else{
            //     int up = grid[row][col];
            //  if(row>0){
            //    up+= dp[row-1][col];
            // }
            // else{
            //     up+=1e9;
            // }
           
            // int down = grid[row][col];
            //  if(col>0){
            //    down+= dp[row][col-1];
            // }
            // else{
            //     down+=1e9;
            // }

            // 2nd way::
            int up=1e9, down=1e9;
            if(row>0){
                up= grid[row][col] + dp[row-1][col];
            }
            if(col>0){
                down= grid[row][col] + dp[row][col-1];
            }
            dp[row][col]= min(up, down);
           }

        }
    }
    return dp[n-1][m-1];
}
int solveSpOpt(vector<vector<int>>&grid, int n, int m){
    vector<int>prev(m,0);
    for(int row=0; row<n; row++){
        vector<int>curr(m,0);
        for(int col=0; col<m; col++){
           if(row==0 && col==0){
               curr[col]=grid[row][col];
           }
           else{
              int up=1e9, down=1e9;
              if(row>0){
                  up= grid[row][col]+ prev[col];
              }
              if(col>0){
                  down=  grid[row][col] + curr[col-1];
              }
              curr[col]= min(up, down);
           }
        }
        prev=curr;
    }
    return prev[m-1];
}
    int minPathSum(vector<vector<int>>& grid) {
     // n-row, m-col 
    int n = grid.size(), m= grid[0].size();

    // // Approach-1: Recursion 
    // int startRow= n-1, startCol= m-1;
    // return solveRec(grid, startRow, startCol);

    // // Approach-2: Memoization
    // int startRow= n-1, startCol= m-1;
    // vector<vector<int>>dp(n, vector<int>(m, -1));
    // return solveMem(grid, startRow, startCol, dp);

    // // Approach-3: Tabulation 
    // return solveTab(grid);

    // Approach-4: Space Optimization 
    return solveSpOpt(grid, n, m);
    }
};