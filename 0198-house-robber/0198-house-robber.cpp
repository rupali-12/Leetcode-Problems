class Solution {
public:
    int solve(vector<int>&nums){
        int n = nums.size();
        int ans= 0;
        int prev2=0, prev1= nums[0];
        for(int i=1; i<n; i++){
            int curr = max((0+prev1), (prev2+nums[i]));
            prev2= prev1;
            prev1= curr;
            ans= max(ans, curr);
        }
        return ans;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        return solve(nums);
    }
};