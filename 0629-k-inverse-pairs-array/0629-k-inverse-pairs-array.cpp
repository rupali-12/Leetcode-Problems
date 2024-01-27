class Solution {
public:
     int mod= 1e9+7;
    
    int dp[1001][1001]={};
    // // Approach -1: Memoization 
    // int kInversePairs(int n, int k) {
    //     if(k<=0) return k==0;
    //     if(dp[n][k]==0){
    //         // dp[n][k]=1;
    //         for(int i=0; i<n; i++){
    //         dp[n][k] = dp[n][k] + kInversePairs(n-1, k-i)%mod;
    //     }
    //     }
    //     return dp[n][k];
    // }
    
    // Approach -2: Tabulation 
    int kInversePairs(int n, int k) {
      int dp[1001][1001]={1};
        for(int N=1; N<=n; N++){
            for(int K=0; K<=k; K++){
                for(int i=0; i<=min(K, N-1); i++){
                    dp[N][K] = (dp[N][K] + dp[N-1][K-i])%mod;
                }
            }
        }
        return dp[n][k];
    }
};