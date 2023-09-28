class Solution {
public:
    
//     int solveRec(vector<int>&nums, int index, 
// int target){
//     if(index==nums.size()){
//         if(target==0) return 1;
//         else return 0;
//     }	
        
//         int include =solveRec(nums, index+1, target+nums[index]);
//         int exclude =solveRec(nums, index+1, target-nums[index]);
//         int ans = include + exclude;
//         return ans;
// }
    
       int solveRec(vector<int>&nums, int index, 
int target, int currSum){
    if(index==nums.size()){
        if(target==currSum) return 1;
        else return 0;
    }	
        
        int include =solveRec(nums, index+1, target, currSum+nums[index]);
        int exclude =solveRec(nums, index+1, target, currSum-nums[index]);
        int ans = include + exclude;
        return ans;
}

    int findTargetSumWays(vector<int>& nums, int target) {
	// //  // approach-1>> Using Recursion 
        int n= nums.size();
	return solveRec(nums, 0, target, 0);

	// // approach-2>> Using Recursion+Memoization 
//  This is a standard backtrack problem where we try for every approach and calculate the desired result.
// But as the max size of array is 20 and total possibilities would be 2^20, this aprroach would result in TLE. Thus, we will need the help of memoization.
    // vector<vector<int>>dp(n, vector<int>(2010, -1));
	// return solveMem(nums, 0, 0,target, dp);

    }
};