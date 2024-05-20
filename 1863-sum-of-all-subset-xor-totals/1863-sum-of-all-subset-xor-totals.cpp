class Solution {
public:
    int solve(vector<int>&nums, int i, int currXor){
       if(i==nums.size()) return currXor;
        int take = solve(nums, i+1, currXor^nums[i]);
        int notTake = solve(nums, i+1, currXor);
        
        return (take + notTake);
    }
    
    int subsetXORSum(vector<int>& nums) {
        int currXor=0;
       return solve(nums, 0, 0);
    }
};