class Solution {
public:
    int n;
    int dp[101];
    int solve(int i, vector<int>&nums){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take = nums[i] + solve(i+2, nums);
        int notTake = solve(i+1, nums);
        return dp[i] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
     n = nums.size();
     memset(dp, -1, sizeof(dp));
     return solve(0, nums);
    }
};