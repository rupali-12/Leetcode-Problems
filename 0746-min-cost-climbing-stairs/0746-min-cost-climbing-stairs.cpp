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
     int solve2(vector<int>&cost, int n){
          vector<int>dp(n+1);
         dp[0]=cost[0];
         dp[1]=cost[1];
       for(int i=2; i<n; i++){
           dp[i]= cost[i]+ min(dp[i-1], dp[i-2]);
       }
         return min(dp[n-1], dp[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // // Approach-1>> Without memoization 
        // int n=cost.size();
        // int ans =min(solve(cost, n-1), solve(cost,n-2));
        // return ans;
        
        //  // Approach-2>> Without memoization 
        // int n=cost.size();
        // vector<int>dp(n+1, -1);
        // int ans =min(solve1(cost, n-1, dp), solve1(cost,n-2, dp));
        // return ans;
        
         // Approach-3>> Tabulation
        int n=cost.size();
        return solve2(cost, n);
    }
};