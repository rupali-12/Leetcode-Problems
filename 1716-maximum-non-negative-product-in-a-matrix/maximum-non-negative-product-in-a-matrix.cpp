class Solution {
public:
  int m, n;
  typedef long long ll;
  int mod =1e9+7;
  vector<vector<pair<ll, ll>>>dp;
  pair<ll, ll>solve(int i, int j, vector<vector<int>>& grid){
    if(i==m-1 && j==n-1){
        return {grid[i][j], grid[i][j]};
    }

    ll maxVal = LLONG_MIN;
    ll minVal = LLONG_MAX;
    
    if(dp[i][j].first != LLONG_MIN && dp[i][j].second!=LLONG_MAX){
        return dp[i][j];
    }
    // down
    if(i+1<m){
        auto [downMax, downMin] = solve(i+1, j, grid);
        maxVal = max({maxVal, grid[i][j]*downMax, grid[i][j]*downMin});
        minVal = min({minVal, grid[i][j]*downMax, grid[i][j]*downMin});
    }

    // right
    if(j+1<n){
        auto [rightMax, rightMin] = solve(i, j+1, grid);
        maxVal = max({maxVal, grid[i][j]*rightMax, grid[i][j]*rightMin});
        minVal = min({minVal, grid[i][j]*rightMax, grid[i][j]*rightMin});
    }

    return dp[i][j] = {maxVal, minVal};
  }
    int maxProductPath(vector<vector<int>>& grid) {
         m=grid.size();
          n= grid[0].size();
       dp= vector<vector<pair<ll, ll>>>(m, vector<pair<ll, ll>>(n, {LLONG_MIN, LLONG_MAX}));
       auto[maxProd, minProd] =solve(0, 0, grid);
       return maxProd<0 ? -1: maxProd%mod;
    }
};