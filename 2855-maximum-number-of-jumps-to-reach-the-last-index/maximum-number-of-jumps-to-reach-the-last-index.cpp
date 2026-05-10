class Solution {
public:
    int n;
    
    int solve(int i, vector<int>& nums, int target, vector<int>&dp){
        if(i==n-1) return dp[i] = 0;

        if(dp[i]!=INT_MIN) return dp[i];
       int result =INT_MIN;
        for(int j=i+1; j<n; j++){
            if(abs(nums[j]-nums[i])<=target){
                int temp = 1+solve(j, nums, target, dp);
                   
                result =max(result, temp);
            }
        }
        return dp[i] = result;
    }
    int maximumJumps(vector<int>& nums, int target) {
         n= nums.size();
        vector<int>dp(n+1, INT_MIN);

        // //  Approach-1: Memoization 
        //  int result= solve(0, nums, target, dp);
        //  return result <0 ? -1: result;

        // Approach-2: Bottom up 
        dp[n-1]=0;
        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(abs(nums[j]-nums[i])<=target && dp[j]!=INT_MIN){
                    int temp= 1+dp[j];
                    dp[i] = max(dp[i], temp);
                } 
            }
        }
        return dp[0] <0 ? -1: dp[0];
    }
};