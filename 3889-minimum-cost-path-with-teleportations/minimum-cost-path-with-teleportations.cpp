class Solution {
public:
int m, n;
   int solve(int i, int j, vector<vector<int>>& grid, vector<vector<vector<int>>>&dp, int k){
      if(i==m || j==n || k<0) return 1e9;
      if(i==m-1 && j==n-1) return 0;
      if(dp[i][j][k]!=-1){
        return dp[i][j][k];
      }

    //   path1: right 
    int path1 =1e9;
    if(j+1 <n){
        path1 = grid[i][j+1] + solve(i, j+1, grid, dp, k);
    }

    // path 2: down 
    int path2 = 1e9;
    if(i+1<m){
        path2 = grid[i+1][j] + solve(i+1, j, grid, dp, k);
    }

    // path 3: teleport 
    int tele = 1e9;
    for(int row=0; row<m; row++){
        for(int col=0; col<n; col++){
            if((row==i && col==j) || grid[row][col]>grid[i][j]){
                continue;
            }
            tele = min(tele, solve(row, col, grid, dp, k-1));
        }
    }

    return dp[i][j][k] = min(tele, min(path1, path2));
   }

    int minCost(vector<vector<int>>& grid, int k) {
        m= grid.size();
        n= grid[0].size();

        // // Approach 1: DP+memoization 
        // vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(k+1, -1)));
        // return solve(0, 0, grid, dp, k);

        // Approach -2: 
        const int INF = 1e9;
    vector<vector<int>> cost(m, vector<int>(n, INF));
    vector<pair<int,int>> cells;   

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cells.push_back({i, j});
        }
    }

    sort(cells.begin(), cells.end(), [&](auto &a, auto &b) {
        return grid[a.first][a.second] < grid[b.first][b.second];
    });

    cost[m-1][n-1] = 0;  // base case

    for (int step = 0; step <= k; step++) {

        vector<vector<int>> prev = cost;   

        // ---- TELEPORT ----
        if (step > 0) {                   
            int best = INF;
            int idx = 0;

            while (idx < cells.size()) {
                int r = cells[idx].first;
                int c = cells[idx].second;
                int val = grid[r][c];

                int j = idx;
                while (j < cells.size() &&
                       grid[cells[j].first][cells[j].second] == val) {
                    best = min(best,
                               prev[cells[j].first][cells[j].second]);
                    j++;
                }

                for (int t = idx; t < j; t++) {
                    cost[cells[t].first][cells[t].second] =
                        min(cost[cells[t].first][cells[t].second], best);
                }

                idx = j;
            }
        }

        // ---- RIGHT & DOWN ----
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) {
                    cost[i][j] = 0;
                    continue;
                }

                if (i + 1 < m)
                    cost[i][j] = min(cost[i][j],
                                     cost[i+1][j] + grid[i+1][j]);

                if (j + 1 < n)
                    cost[i][j] = min(cost[i][j],
                                     cost[i][j+1] + grid[i][j+1]);
            }
        }
    }

    return cost[0][0];
    }
};