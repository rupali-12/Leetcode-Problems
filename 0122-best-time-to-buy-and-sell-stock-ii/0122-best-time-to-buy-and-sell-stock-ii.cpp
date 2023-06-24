class Solution {
public:

// // Approach-1 >>
//     int maxProfit(vector<int>& prices) {
//         int profit=0;
//         for(int i=1; i<prices.size();i++){
//             if(prices[i]>prices[i-1]){
//                 profit+= prices[i]-prices[i-1];
//             }
//         }
//         return profit;
//     }

// Approach-2> Using DP 
int solveRec(vector<int>& prices, int index, int buy){
    if(index==prices.size()){
        return 0;
    }
int profit=0;
    if(buy){
       profit = max(( -prices[index] + solveRec(prices, index+1, 0)), ( 0 + solveRec(prices, index+1, 1)));
    }
    else{
      profit = max(( +prices[index] + solveRec(prices, index+1, 1)), ( 0 + solveRec(prices, index+1, 0)));
    }
    return profit;
}

int solveMem(vector<int>& prices, int index, int buy,  vector<vector<int>>&dp){
    if(index==prices.size()){
        return 0;
    }
    if(dp[index][buy]!=-1){
        return dp[index][buy];
    }
     int profit=0;
    if(buy){
       profit = max(( -prices[index] + solveRec(prices, index+1, 0)), ( 0 + solveRec(prices, index+1, 1)));
    }
    else{
      profit = max(( +prices[index] + solveRec(prices, index+1, 1)), ( 0 + solveRec(prices, index+1, 0)));
    }
   return dp[index][buy] =profit;   
}

int solveTab(vector<int>& prices){
    int n=prices.size();
    vector<vector<int>>dp(n+1, vector<int>(2, 0));
    int profit=0;
    for(int index=n-1; index>=0; index--){
        for(int buy=0; buy<=1; buy++){
            if(buy){
              profit= max((-prices[index] +dp[index+1][0]), (0 + dp[index+1][1]));
            }
            else{
              profit= max((prices[index] +dp[index+1][1]), (0 + dp[index+1][0]));
            }
        dp[index][buy] =profit;
        }
    }
    return dp[0][1];
}

int solveTabSpOpt(vector<int>& prices){
    int n=prices.size();
    vector<int>curr(2, 0);
    vector<int>next(2, 0);
    int profit=0;
    for(int index=n-1; index>=0; index--){
        for(int buy=0; buy<=1; buy++){
            if(buy){
              profit= max((-prices[index]+ next[0]), (0 + next[1]));
            }
            else{
              profit= max((prices[index]+ next[1]), (0 + next[0]));
            }
            curr[buy] = profit;
        }
       next=curr;
    }
  //  return curr[1];
   return next[1];
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
    // //  Method-1: Using Recursion 
    // // index, buy 
    //   return solveRec(prices, 0, 1);

    //  //  Method-2: Using Recursion + Memoization 
    // // index, buy 
    // vector<vector<int>>dp(n, vector<int>(2, -1));
    //   return solveMem(prices, 0, 1, dp);

    //  //  Method-3: Using Tabulation(top down) 
    //   return solveTab(prices);

      //  Method-4: Using Tabulation(top down) + space optimization 
      return solveTabSpOpt(prices);
    }
};