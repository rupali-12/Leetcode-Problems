class Solution {
public:
    long long dp[1001][501][3];

    // CASES:
    // 0-> you have not brough , not sold, fresh transaction 
    // 1->  (Normal transaction) you have brought, now you have to sell 
    // 2-> (Short selling transaction) you have sold, not you can buy only 

    long long solve(int i, int k, int CASE, vector<int>&prices){
       if(i>= prices.size()){
        if(CASE==0) return 0;  // all existing transaction completed now u r out of bound so valid case
        return INT_MIN;   // Invalid case, incomplete transaction with out of bound
       }
       
      if(dp[i][k][CASE]!=INT_MIN){
        return dp[i][k][CASE];
      }

       long long take = INT_MIN;
       long long notTake = solve(i+1, k, CASE, prices);   // do nothing

        if(k>0){
            if(CASE==1){
            // sell today -> complete normal transaction 
              take = prices[i] + solve(i+1, k-1, 0, prices);  // after selling fresh so CASE==0
            }
            else if(CASE==2){
            // buy today -> complete short selling transaction
              take = -prices[i] + solve(i+1, k-1, 0, prices);
            }
            else{
                // CASE==0 start fresh transaction 
                take = max((-prices[i]+solve(i+1, k, 1, prices)), (prices[i]+solve(i+1, k, 2, prices)));
                // here with '-' we use 1 means we buy it so now we can sell only 
            }
        }
       return dp[i][k][CASE] = max(take, notTake);
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n= prices.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<=k; j++){
                for(int K=0; K<3; K++){
                    dp[i][j][K]=INT_MIN;
                }
            }
        }
        return solve(0, k, 0, prices);    // k, 0(initially fresh case)
    }
};