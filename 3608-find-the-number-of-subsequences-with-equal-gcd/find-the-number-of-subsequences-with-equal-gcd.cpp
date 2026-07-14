class Solution {
public:
    int dp[201][201][201];
    int mod = 1e9+7;
    int solve(vector<int>&nums, int i, int first, int second){
        if(i==nums.size()){
           bool bothNonEmpty = (first!=0 && second !=0);
           bool isGcdEqual = (first == second);
           return bothNonEmpty && isGcdEqual;
        }

        if(dp[i][first][second]!=-1){
            return dp[i][first][second];
        }

        int skip = solve(nums, i+1, first, second);
        int take1 = solve(nums, i+1, __gcd(first, nums[i]), second);
        int take2 = solve(nums, i+1, first, __gcd(second, nums[i]));
        return dp[i][first][second] = (skip + (take1 + take2)%mod)%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 0, 0);
    }
};