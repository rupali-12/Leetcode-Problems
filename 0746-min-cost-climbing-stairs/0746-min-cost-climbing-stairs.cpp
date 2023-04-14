class Solution {
public:
    int solve(vector<int>& cost, int n){
        if(n==0 || n==1){
            return cost[n];
        }
        int ans = cost[n]+min(solve(cost, n-1), solve(cost,n-2));
        return ans;
    }
     int solve1(vector<int>& cost, int n, vector<int>&dp){
        if(n==0 || n==1){
            return cost[n];
        }
         if(dp[n]!=-1){
             return dp[n];
         }
        dp[n]= cost[n]+min(solve1(cost, n-1, dp), solve1(cost,n-2, dp));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // // Approach-1>> Without memoization 
        // int n=cost.size();
        // int ans =min(solve(cost, n-1), solve(cost,n-2));
        // return ans;
        
         // Approach-1>> Without memoization 
        int n=cost.size();
        vector<int>dp(n+1, -1);
        int ans =min(solve1(cost, n-1, dp), solve1(cost,n-2, dp));
        return ans;
    }
};