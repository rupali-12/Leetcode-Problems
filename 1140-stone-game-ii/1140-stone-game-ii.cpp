class Solution {
public:
    int n;
    int dp[101][10001][2];
    int solve(vector<int>&piles, int aliceTurn, int i, int M){
        if(i>=n) return 0;
        int result = (aliceTurn==1)? -1 : INT_MAX;
        if(dp[i][M][aliceTurn]!=-1) return dp[i][M][aliceTurn];
        int stones =0;
        for(int x=1; x<= min(2*M, n-i); x++){
            stones+= piles[i+x-1];  // -1 as 0-based index
          if(aliceTurn ==1){
            result = max(result, stones+solve(piles, 0, i+x, max(M, x)));
          }
          else{    // bob turn
            result = min(result, solve(piles, 1, i+x, max(M, x)));
          }
        }
        return dp[i][M][aliceTurn] = result;
    }
    int stoneGameII(vector<int>& piles) {
        n= piles.size();
        memset(dp, -1, sizeof(dp));
        return solve(piles, 1, 0, 1);   // (alice turn, index, M)
    }
};