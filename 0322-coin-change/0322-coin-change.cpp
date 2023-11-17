class Solution {
public:
    int solveRec(vector<int>& coins, int amount, int index){
        if(index==0){
            if(amount%coins[index]==0){
                return amount/coins[index];   // index=0 here
            }
            else return 1e9;
        }
        
        int take=INT_MAX;;
        int notTake= solveRec(coins, amount, index-1);
        if(coins[index]<=amount){
            take= 1+ solveRec(coins, amount-coins[index], index);
        }
        return min(take, notTake);
    }
        int solveMem(vector<int>& coins, int amount, int index, vector<vector<int>>&dp){
        if(index==0){
            if(amount%coins[index]==0){
                return amount/coins[index];   // index=0 here
            }
            else return 1e9;
        }
            if(dp[index][amount]!=-1){
                return dp[index][amount];
            }
        
        int take=INT_MAX;;
        int notTake= solveMem(coins, amount, index-1, dp);
        if(coins[index]<=amount){
            take= 1+ solveMem(coins, amount-coins[index], index, dp);
        }
        return dp[index][amount] =  min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        
        // // Approach-1: Recursion 
        // int ans = solveRec(coins, amount, n-1);
        
         // Approach-2: Recursion + Memoization 
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans = solveMem(coins, amount, n-1, dp);
        
        if(ans==1e9) return -1;
        return ans;
    }
};