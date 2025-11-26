class Solution {
public:
int m, n;
const int MOD = 1e9 + 7;
  int solveRec(int i, int j, vector<vector<int>>& grid, int currSum, int k){
    if(i>=m || j>=n){
        return 0;
    }

    if(i==m-1 && j==n-1){
        // Here we are at last cell
        return (currSum+grid[i][j])%k==0? 1:0;
    }
    int right=0, down=0;
    if(j+1<n){
     right = solveRec(i, j+1, grid, currSum+grid[i][j], k);
    }
    if(i+1<m){
     down = solveRec(i+1, j, grid, currSum+grid[i][j], k);
    }
    return (right+down)%MOD;
  }

  int solveRecMem(int i, int j, vector<vector<int>>& grid, int rem, int k, vector<vector<vector<int>>>&dp){
    if(i>=m || j>=n){
        return dp[i][j][rem] =0;
    }
     rem = (rem + grid[i][j])%k;
    if(i==m-1 && j==n-1){
        // Here we are at last cell
        return dp[i][j][rem] = rem==0? 1:0;
    }
    if(dp[i][j][rem]!=-1){
        return dp[i][j][rem];
    }
    int right=0, down=0;
    if(j+1<n){
     right = solveRecMem(i, j+1, grid, rem, k, dp);
    }
    if(i+1<m){
     down = solveRecMem(i+1, j, grid, rem, k, dp);
    }
    return dp[i][j][rem] = (right+down)%MOD;
  }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m= grid.size();
        n= grid[0].size();
        // // Approach1: Recursion 
        // int currSum=0;
        // return solveRec(0, 0, grid, currSum, k);

        // // Approach1: Recursion + Memoization
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(k, -1)));
        int rem=0;
        return solveRecMem(0, 0, grid, rem, k, dp);

    }
};