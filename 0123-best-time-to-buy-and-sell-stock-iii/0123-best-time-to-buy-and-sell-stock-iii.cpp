class Solution {
public:
//    int solveRec(vector<int>&prices, int index, int buy, int limit){
//     if(index==prices.size()){
//         return 0;
//     }
//     if(limit==0){
//         return 0;
//     }
//     int profit=0;
//     if(buy){
//      profit= max((-prices[index]+solveRec(prices, index+1, 0, limit)), (0+ solveRec(prices, index+1, 1, limit)));
//     }
//     else{
//     profit= max((prices[index]+solveRec(prices, index+1, 1, limit-1)), (0+ solveRec(prices, index+1, 0, limit)));
//     }
//     return profit;
//    }
//    int solveMem(vector<int>&prices, int index, int buy, int limit, vector<vector<vector<int>>>&dp){
//        if(index==prices.size() || limit==0){
//            return 0;
//        }
//        if(dp[index][buy][limit]!=-1){
//            return dp[index][buy][limit];
//        }
//        int profit=0;
//        if(buy){
//            profit = max((-prices[index]+solveMem(prices, index+1, 0, limit, dp)), (0+solveMem(prices, index+1, 1, limit, dp)));
//        }
//        else{
//         profit = max((prices[index]+solveMem(prices, index+1, 1, limit-1, dp)), (0+solveMem(prices, index+1, 0, limit, dp)));
//        }
//        return dp[index][buy][limit]= profit;
//    }
//    int solveTab(vector<int>&prices){
//          int n= prices.size();
//     vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
//     int profit=0;
//     for(int index=n-1; index>=0; index--){
//         for(int buy=0; buy<2; buy++){
//             for(int limit=1; limit<=2; limit++){
//               if(buy){
//                profit= max((-prices[index]+dp[index+1][0][limit]), (0+ dp[index+1][1][limit]));
//               }
//               else{
//                  profit= max((prices[index]+dp[index+1][1][limit-1]), (0+ dp[index+1][0][limit]));
//               }
//               dp[index][buy][limit]= profit;
//             }
//         }
//     }
//      return dp[0][1][2];
//    }
//    int solveSpOpt(vector<int>&prices){
//         int n= prices.size();
//    vector<vector<int>>curr(2, vector<int>(3, 0));
//    vector<vector<int>>next(2, vector<int>(3, 0));
//     int profit=0;
//     for(int index=n-1; index>=0; index--){
//         for(int buy=0; buy<2; buy++){
//             for(int limit=1; limit<=2; limit++){
//               if(buy){
//                profit= max((-prices[index]+next[0][limit]), (0+ next[1][limit]));
//               }
//               else{
//                  profit= max((prices[index]+next[1][limit-1]), (0+ next[0][limit]));
//               }
//               curr[buy][limit]= profit;
//             }
//         }
//         next=curr;
//     }
//      return next[1][2];
//    }
//     int maxProfit(vector<int>& prices) {
// //    Approach-0: 
// //  int minPrice1=INT_MAX, minPrice2= INT_MAX, maxProfit1=0, maxProfit2=0;
// //      for(int i=0; i<prices.size(); i++){
// //          minPrice1 =min(minPrice1, prices[i]);
// //          maxProfit1 =max(maxProfit1, prices[i]-minPrice1);
// //          minPrice2 =min(minPrice2, prices[i]-maxProfit1);
// //          maxProfit2 =max(maxProfit2, prices[i]-minPrice2);
// //      }
// //      return maxProfit2;

//     // //    Approach-2> Using Recursion 
//     // // (prices, index, buy, limit)
//     // return solveRec(prices, 0, 1, 2);

//         // // Approach-2> Using Recursion + Memoization
//         // int n =prices.size();
//         // // index   buy   limit 
//         // vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
//         // return solveMem(prices, 0, 1, 2, dp);

//         //   // Approach-3> Using Tabulation 
//         // return solveTab(prices);

//            // Approach-4> Using Tabulation + space optimization
//         return solveSpOpt(prices);
    // }
    
    
    // *******************************************************************************
    
    int maxProfit(vector<int>& prices) {
    // Approach-1: 
        int min_price1=INT_MAX, min_price2= INT_MAX, maxProfit1=0, maxProfit2=0;
        for(int i=0; i<prices.size(); i++){
            min_price1= min(min_price1, prices[i]);
            maxProfit1 = max(maxProfit1, prices[i]-min_price1);
             min_price2= min(min_price2, prices[i]-maxProfit1);
            maxProfit2 = max(maxProfit2, prices[i]-min_price2);
        }
        return maxProfit2;
    }
};