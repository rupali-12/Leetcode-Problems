class Solution {
public:
    vector<vector<int>>adj={{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1,7, 0}, {2, 6},{1,3}, {2,4}};
    int mod= 1e9+7;
    int solveRec(int n, int cell, vector<vector<int>>&dp){
        if(n==0) return 1;
        int ans=0;
        if(dp[n][cell]!=-1){
            return dp[n][cell];
        }
        for(int &nextcell: adj[cell]){
            ans= (ans+ solveRec(n-1, nextcell, dp))%mod;
        }
        return dp[n][cell] = ans;
    }
    int knightDialer(int n) {
        // Approach-1,2: Recursion + Memoization 
        int result=0;
        vector<vector<int>>dp(5001, vector<int>(10, -1));
        for(int cell=0; cell<=9; cell++){
            result=( result+ solveRec(n-1, cell, dp))%mod;
        }
        return result;
    }
};