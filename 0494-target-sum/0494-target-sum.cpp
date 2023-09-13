class Solution {
public:
    
    int solveRec(vector<int>&nums, int index, 
int target){
	// if only one item is to steal
	if(index==nums.size()){
		if(target==0){
			return 1;
		}
		else{
			return 0;
		}
	}
	
	// case of include 
	int include= solveRec(nums, index+1, target+nums[index]);
	// case of exclude 
	int exclude = solveRec(nums, index+1, target-nums[index]);
	int ans= include + exclude;   // total ways
	return ans;

}
    int findTargetSumWays(vector<int>& nums, int target) {
      //  // approach-1>> Using Recursion 
        int n= nums.size();
	return solveRec(nums, 0, target);

	// // // approach-2>> Using Recursion+Memoization 
    // vector<vector<int>>dp(n, vector<int>(target+1, -1));
	// return solveMem(nums, value, n-1, target, dp);

	// // approach-3>> Using Tabulation 
    //  return solveTab(nums, value, n, target);

	// // approach-4>> Using Space optimization 
	// return solveSpOpt(nums,  n,  target);
    }
};