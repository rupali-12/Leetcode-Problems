class Solution {
public:
    int solveMem(vector<int>& arr, int i, int k, vector<int>&dp){
        int n = arr.size();
        if(i==arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int len=0, maxi=INT_MIN, maxAns = INT_MIN;
        for(int j=i; j<min(n, i+k); j++){
            len++;
            maxi = max(maxi, arr[j]);
            int sum= len*maxi + solveMem(arr, j+1, k, dp);
            maxAns= max(maxAns, sum);
        }
        return dp[i] = maxAns;
    }
    int solveTab(vector<int>&arr, int k){
        int n =arr.size();
        vector<int>dp(n+1, 0);
       for (int i = n - 1; i >= 0; i--) {
            int len = 0, maxi = INT_MIN, maxAns = INT_MIN;

            for (int j = i; j < min(n, i + k); j++) {
                len++;
                maxi = max(maxi, arr[j]);
                int sum = len * maxi + dp[j + 1];
                maxAns = max(maxAns, sum);
            }

            dp[i] = maxAns;
        }
        return dp[0];
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // // Memoization
        // vector<int>dp(arr.size(), -1);
        // return solveMem(arr, 0, k, dp);
        
        // Tabulation 
        return solveTab(arr, k);
    }
};