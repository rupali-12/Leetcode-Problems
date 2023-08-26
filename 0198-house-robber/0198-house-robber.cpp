class Solution {
public:
    int solveOpt(vector<int>&nums){
    int prev2= 0;
    int prev1= nums[0];
    for(int i=1;i<nums.size(); i++){
        int curr = max((0+prev1), (nums[i]+prev2));
        prev2=prev1;
        prev1= curr;
    }
    return prev1;
}
    int rob(vector<int>& nums) {
            return solveOpt(nums);
    }
};