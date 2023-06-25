// class Solution {
// public:

//     // //  Method-1>> Without using Transaction Number
//     // int solveSpOpt(vector<int>&prices, int k){
//     //    vector<vector<int>>curr(2, vector<int>(k+1, 0));
//     //    vector<vector<int>>next(2, vector<int>(k+1, 0));
//     //    int profit=0;
//     //    int n= prices.size();
//     //    for(int index= n-1; index>=0; index--){
//     //      for(int buy=0; buy<=1; buy++){
//     //          for(int limit=1; limit<=k; limit++){
//     //              if(buy){
//     //                  profit= max((-prices[index]+next[0][limit]), (0+next[1][limit]));
//     //              }
//     //              else{
//     //                  profit= max((prices[index]+next[1][limit-1]), (0+next[0][limit]));
//     //              }
//     //              curr[buy][limit]=profit;
//     //          }
//     //      }
//     //      next= curr;
//     //    }
//     //    return next[1][k];
//     // }
//     // int maxProfit(int k, vector<int>& prices) {
//     // // Approach-1-> Using Tabulation + space optimization
//     //    return solveSpOpt(prices, k);

// // **************************************************************************************
//  //  Method-1>> Using Transaction Number
//    int solveRec(vector<int>&prices, int index, int operationNo, int k){
//        if(index==prices.size()){
//            return 0;
//        }
//        if(operationNo==2*k){
//            return 0;
//        }
//        int profit=0;
//        if(operationNo%2==0){
//           profit= max((-prices[index]+solveRec(prices, index+1, operationNo+1, k)), (0+solveRec(prices, index+1, operationNo, k)));
//        }
//        else{
//          profit= max((prices[index]+solveRec(prices, index+1, operationNo+1, k)), (0+solveRec(prices, index+1, operationNo, k)));
//        }
//        return profit;
//    }

//     int solveMem(vector<int>&prices, int index, int operationNo, int k, vector<vector<int>>&dp){
//        if(index==prices.size()){
//            return 0;
//        }
//        if(operationNo==2*k){
//            return 0;
//        }
//        if(dp[index][operationNo]!=-1){
//            return dp[index][operationNo];
//        }
//        int profit=0;
//        if(operationNo%2==0){
//           profit= max((-prices[index]+solveMem(prices, index+1, operationNo+1, k, dp)), (0+solveMem(prices, index+1, operationNo, k, dp)));
//        }
//        else{
//          profit= max((prices[index]+solveMem(prices, index+1, operationNo+1, k, dp)), (0+solveMem(prices, index+1, operationNo, k, dp)));
//        }
//        return dp[index][operationNo]= profit;
//    }
   
//    int solveTab(vector<int>&prices, int k){
//      int n= prices.size();
//     vector<vector<int>>dp(n+1, vector<int>(2*k+1, 0));
//    dp[n][2*k]=0;
//     int profit=0;
//     for(int index=n-1; index>=0; index--){
//         for(int operationNo=0; operationNo<2*k; operationNo++){
//          if(operationNo%2==0){
//           profit= max((-prices[index]+dp[index+1][operationNo+1]), (0+dp[index+1][operationNo]));
//        }
//        else{
//     profit= max((prices[index]+dp[index+1][operationNo+1]), (0+dp[index+1][operationNo]));
//        }
//         dp[index][operationNo]=profit;
//         }
//     }
//     return dp[0][0];
//    }
//     int solveSpOpt(vector<int>&prices, int k){
//        vector<int>curr(2*k+1, 0);
//        vector<int>next(2*k+1, 0);
//         int n= prices.size();
//     vector<vector<int>>dp(n+1, vector<int>(2*k+1, 0));
//    dp[n][2*k]=0;
//     int profit=0;
//     for(int index=n-1; index>=0; index--){
//         for(int operationNo=0; operationNo<2*k; operationNo++){
//          if(operationNo%2==0){
//           profit= max((-prices[index]+next[operationNo+1]), (0+next[operationNo]));
//        }
//        else{
//     profit= max((prices[index]+next[operationNo+1]), (0+next[operationNo]));
//        }
//         curr[operationNo]=profit;
//         }
//         next= curr;
//     }
//     return next[0];
//     }
//     int maxProfit(int k, vector<int>& prices) {
//     // // Approach-1-> Using Recursion
//     // // index, operationNo, k
//     // return solveRec(prices, 0, 0, k);

//     //  // Approach-2-> Using Recursion + Memoization
//     // // index, operationNo, k
//     // int n= prices.size();
//     // vector<vector<int>>dp(n+1, vector<int>(2*k, -1));
//     // return solveMem(prices, 0, 0, k, dp);

//     //  // Approach-3-> Using Tabulation(Bottom up)
//     // return solveTab(prices, k);

//     // Approach-4-> Using Tabulation + space optimization
//        return solveSpOpt(prices, k);

//     }
// };

// ****************************************************************************************
class Solution {
public:
    int solveRec(vector<int>& prices, int index, int buy, int limit){
        if(index==prices.size()){
            return 0;
        }
        if(limit==0) return 0;
        int profit=0;
        if(buy){
            profit= max((-prices[index]+solveRec(prices, index+1, 0, limit)), (0+ solveRec(prices, index+1, 1, limit)));
        }
        else{
             profit= max((prices[index]+solveRec(prices, index+1, 1, limit-1)), (0+ solveRec(prices, index+1, 0, limit)));
        }
        return profit;
    }
    
    int solveMem(vector<int>& prices, int index, int buy, int limit, vector<vector<vector<int>>>&dp){
        if(index==prices.size()){
            return 0;
        }
        if(limit==0) return 0;
        if(dp[index][buy][limit]!=-1){
            return dp[index][buy][limit];
        }
        int profit=0;
        if(buy){
            profit = max((-prices[index]+ solveMem(prices, index+1, 0, limit, dp)), (0 +solveMem(prices, index+1, 1, limit, dp)));
        }
        else{
           profit = max((prices[index]+ solveMem(prices, index+1, 1, limit-1, dp)), (0 +solveMem(prices, index+1, 0, limit, dp))); 
        }
     return dp[index][buy][limit]=profit;                   
    }
    
    int solveTab(vector<int>& prices, int k){
        int n= prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        int profit=0;
        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<2;buy++){
                for(int limit=1; limit<k+1; limit++){
                    if(buy){
                        profit= max((-prices[index] + dp[index+1][0][limit]), (0 +dp[index+1][1][limit]));
                    }
                    else{
                          profit= max((prices[index] + dp[index+1][1][limit-1]), (0 +dp[index+1][0][limit]));  
                    }
                    dp[index][buy][limit]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
      int solveTabSpOpt(vector<int>& prices, int k){
        int n= prices.size();
        vector<vector<int>>curr(2, vector<int>(k+1, 0));
        vector<vector<int>>next(2, vector<int>(k+1, 0));
        int profit=0;
        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1;buy++){
                for(int limit=1; limit<=k; limit++){
                    if(buy){
                        profit= max((-prices[index] + next[0][limit]), (0 +next[1][limit]));
                    }
                    else{
                          profit= max((prices[index] +next[1][limit-1]), (0 +next[0][limit]));  
                    }
                    curr[buy][limit]=profit;
                }
            }
            next=curr;
        }
        return curr[1][k];
        // return next[1][2];
    }
    int maxProfit(int k, vector<int>& prices) {
    // // Approach-1: 
    //     int min_price1=INT_MAX, min_price2= INT_MAX, maxProfit1=0, maxProfit2=0;
    //     for(int i=0; i<prices.size(); i++){
    //         min_price1= min(min_price1, prices[i]);
    //         maxProfit1 = max(maxProfit1, prices[i]-min_price1);
    //          min_price2= min(min_price2, prices[i]-maxProfit1);
    //         maxProfit2 = max(maxProfit2, prices[i]-min_price2);
    //     }
    //     return maxProfit2;
        
        // Approach-2: Using DP 
                int n=prices.size();
        // // method-1: Using Recursion
        // // (index, buy, limit)
        // return solveRec(prices, 0, 1, k);
        
       //  // method-2: Using Recursion +Memoization 
       //  // // (index, buy, limit)
       // vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
       //  return solveMem(prices, 0, 1, k, dp);
        
        // method-3: Using Tabulation
        // return solveTab(prices, k);
        
        //  // method-4: Using Tabulation + Space optimization
        return solveTabSpOpt(prices, k);
    }
};