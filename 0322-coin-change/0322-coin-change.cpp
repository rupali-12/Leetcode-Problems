class Solution {
public:
 
    int  solveRec(vector<int>coins, int amount, int index){
        if(index==0) {
            if(amount%coins[0]==0){
                return amount/coins[0];   // min coin tha we can return
            }
            else return 1e9;
        }
        
        int ans= 0, take=INT_MAX;
        int notTake= solveRec(coins, amount, index-1);
        if(coins[index]<= amount){
            take = 1 + solveRec(coins, amount-coins[index], index);
        }
        ans= min(take, notTake);
        return ans;
    }
     int  solveMem(vector<int>coins, int amount, int index, vector<vector<int>>&dp){
        if(index==0) {
            if(amount%coins[0]==0){
                return amount/coins[0];   // min coin tha we can return
            }
            else return 1e9;
        }
         if(dp[index][amount]!=-1){
             return dp[index][amount];
         }
        
        int ans= 0, take=INT_MAX;
        int notTake= solveMem(coins, amount, index-1, dp);
        if(coins[index]<= amount){
            take = 1 + solveMem(coins, amount-coins[index], index, dp);
        }
        ans= min(take, notTake);
        return dp[index][amount]= ans;
    }
    
    int solveTab(vector<int>& coins, int amount, int n){
          vector<vector<int>>dp(n+1, vector<int>(amount+1, 0));
        for(int t=0; t<=amount; t++){
            if(t%coins[0]==0) dp[0][t]=t/coins[0];
            else dp[0][t]= 1e9;
        }
        
        for(int index=1; index<n; index++){
            for(int t = 0; t<=amount; t++){
                int notTake = dp[index-1][t];
                int take= INT_MAX;
                if(coins[index]<=t){
                    take = 1 + dp[index][t-coins[index]];
                }
                dp[index][t] = min(take, notTake);
            }
        }
        return dp[n-1][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
      int n = coins.size();
        
        // // Approach-1: Recursion 
        // int ans = solveRec(coins, amount, n-1);
        
        //   // Approach-2: Recursion +Memoization
        // vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        // int ans = solveMem(coins, amount, n-1, dp);
        
         // Approach-3: Tabulation
        int ans = solveTab(coins, amount, n);
        
        if(ans==(1e9)) return -1;
        return ans;
    }
};