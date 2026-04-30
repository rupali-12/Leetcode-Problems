class Solution {
public:
    int m, n;
    vector<vector<vector<int>>>dp;
    int solve(vector<vector<int>>& grid, int i, int j, int cost, int k){
        if(i>=m || j>=n) return INT_MIN;

        int currCost = grid[i][j] == 0? 0: 1;
        int currScore=grid[i][j];

        cost+= currCost;

        // if invalid cost
        if(cost >k) return INT_MIN;
        if(i==m-1 && j==n-1){
            return dp[i][j][cost] = currScore;
        }

        if(dp[i][j][cost]!=-1){
            return dp[i][j][cost];
        }

        int down = solve(grid, i+1, j, cost, k);
        int right = solve(grid, i, j+1, cost, k);

        int best = max(down, right);
        if(best==INT_MIN) return dp[i][j][cost]= INT_MIN;
        return dp[i][j][cost] = currScore + best;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(k+1, -1)));
        int ans = solve(grid, 0, 0, 0, k);
        return ans==INT_MIN? -1: ans;
    }
};