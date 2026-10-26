class Solution {
public:
    int m, n;
    int ans;
    long long getIslandSum(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return 0;
        
        if(grid[i][j]==0) return 0;

        long long sum = grid[i][j];
        grid[i][j] = 0;

        sum+= getIslandSum(grid, i, j - 1);
        sum+= getIslandSum(grid, i - 1, j);
        sum+= getIslandSum(grid, i, j + 1);
        sum+= getIslandSum(grid, i + 1, j);
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        ans = 0;
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                   long long res = getIslandSum(grid, i, j);
                   if (res % k == 0) ans++;
                }
            }
        }
        return ans;
    }
};