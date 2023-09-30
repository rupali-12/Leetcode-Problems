class Solution {
public:
     int solveRec(vector<int>& coins, int amount, int index){
    // if(index==0){
    //     return amount%coins[0]==0;
    // }
    
    // way 2>
    if(index<0) return 0;
    if(amount==0) return 1;
       int ans=0;
      if(coins[index]<=amount){
          ans = solveRec(coins, amount-coins[index], index) + solveRec(coins, amount, index-1);
      }
      else{
          ans= solveRec(coins, amount, index-1);
      }
      return ans;
  }
  int solveMem(vector<int>coins, int amount, int index,  vector<vector<int>>&dp){
    // if(index==0){
    //     return value%denomina[0]==0;
    // }
    
    // way 2>
    if(index<0) return 0;
    if(amount==0) return 1;
    if(dp[index][amount]!=-1){
        return dp[index][amount];
    }
    
       int ans=0, take=0;
       int notTake= solveMem(coins, amount, index-1, dp);
      if(coins[index]<=amount){
          take = solveMem(coins, amount-coins[index], index, dp);
      }
      ans = take+notTake;
      return dp[index][amount]= ans;
  }
 
    int change(int amount, vector<int>& coins) {
         int n = coins.size();
        
        // // // Approach-1: Recursion 
        // return solveRec(coins, amount, n-1);
        
         // // Approach-2: Recursion + Memoization 
     vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        return solveMem(coins, amount, n-1, dp);
        
      
    }
};