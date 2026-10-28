class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // dp[j][x] = can we reach current row's cell (i,j)
        // with XOR value x?
        vector<bitset<1024>> dp(n);

        dp[0].set(grid[0][0]);

        for (int j = 1; j < n; j++) {
            for (int x = 0; x < 1024; x++) {
                if (dp[j - 1][x]) {
                    dp[j].set(x ^ grid[0][j]);
                }
            }
        }

        for (int i = 1; i < m; i++) {
            // Update first column: only possible from above
            bitset<1024> firstCol;
            for (int x = 0; x < 1024; x++) {
                if (dp[0][x]) {
                    firstCol.set(x ^ grid[i][0]);
                }
            }
            dp[0] = firstCol;

            for (int j = 1; j < n; j++) {
                bitset<1024> cur;

                // Paths arriving from above
                for (int x = 0; x < 1024; x++) {
                    if (dp[j][x]) {
                        cur.set(x ^ grid[i][j]);
                    }
                }

                // Paths arriving from the left
                for (int x = 0; x < 1024; x++) {
                    if (dp[j - 1][x]) {
                        cur.set(x ^ grid[i][j]);
                    }
                }

                dp[j] = cur;
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[n - 1][x]) return x;
        }

        return -1;
    }
};