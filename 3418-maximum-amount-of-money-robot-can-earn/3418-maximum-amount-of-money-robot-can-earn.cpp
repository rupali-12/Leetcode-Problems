class Solution {
public:
int m, n;
vector<vector<vector<int>>>dp;
    int solve(vector<vector<int>>& coins, int i, int j, int neu){
        if(i==m-1 && j==n-1){
            if(coins[i][j]<0 && neu>0){
                return dp[i][j][neu] = 0; // return 0 from that cell if have chance to neutralize robber
            }
            return dp[i][j][neu] = coins[i][j];
        }

        if(i>=m || j>=n){
            return INT_MIN;
        }
        if(dp[i][j][neu]!=INT_MIN){
            return dp[i][j][neu];
        }

        int take = coins[i][j] + max(solve(coins, i+1, j, neu), solve(coins, i, j+1, neu));
        int notTake=INT_MIN;
        if(coins[i][j]<0 && neu>0){
            notTake = max(solve(coins, i+1, j, neu-1), solve(coins, i, j+1, neu-1));
        }
        return dp[i][j][neu] =max(take, notTake);
    }
    int maximumAmount(vector<vector<int>>& coins) {
         m=coins.size(), n=coins[0].size();
         dp.assign(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
         return solve(coins, 0, 0, 2);
    }
};