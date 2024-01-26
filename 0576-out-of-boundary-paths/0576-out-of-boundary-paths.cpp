class Solution {
public:
   long int mod = 1e9 + 7;
     int dp[51][51][51];
   int solve(int m, int n, int i, int j, int numMove) {
        if (i < 0 || i >= m || j < 0 || j >= n) return 1;
        if (numMove <= 0) return 0;
        if (dp[i][j][numMove] != -1) {
            return dp[i][j][numMove];
        }
         int up = solve(m, n, i - 1, j, numMove - 1) ;
         int down = solve(m, n, i + 1, j, numMove - 1) ;
         int left = solve(m, n, i, j - 1, numMove - 1) ;
         int right = solve(m, n, i, j + 1, numMove - 1) ;

        return dp[i][j][numMove] = ((up + down)%mod + (left + right)%mod) % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // Approach: Recursion + Memoization
       memset(dp, -1, sizeof(dp));  // Correct usage of memset
        return solve(m, n, startRow, startColumn, maxMove);
    }
};