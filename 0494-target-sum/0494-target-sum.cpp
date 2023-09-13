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
        int solveMem(vector<int>&nums, int index, int currSum, 
int target, vector<vector<int>>&dp){
	// if only one item is to steal
	if(index==nums.size()){
		if(currSum==target){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(dp[index][currSum+1010]!=-1){
        return dp[index][currSum+1010];
    }
	// case of include 
	int include= solveMem(nums, index+1, currSum+nums[index], target, dp);
	// case of exclude 
	int exclude = solveMem(nums, index+1, currSum-nums[index], target, dp);
	int ans= include + exclude;   // total ways
	return  dp[index][currSum+1010]= ans;

}
    int findTargetSumWays(vector<int>& nums, int target) {
	// //  // approach-1>> Using Recursion 
        int n= nums.size();
	// return solveRec(nums, 0, target);

	// // approach-2>> Using Recursion+Memoization 
//  This is a standard backtrack problem where we try for every approach and calculate the desired result.
// But as the max size of array is 20 and total possibilities would be 2^20, this aprroach would result in TLE. Thus, we will need the help of memoization.
    vector<vector<int>>dp(n, vector<int>(2010, -1));
	return solveMem(nums, 0, 0,target, dp);

    }
};