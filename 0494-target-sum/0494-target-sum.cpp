class Solution {
public:
    
//     int solveRec(vector<int>&nums, int index,  int target){
//     if(index==nums.size()){
//         if(target==0) return 1;
//         else return 0;
//     }	
        
//         int include =solveRec(nums, index+1, target+nums[index]);
//         int exclude =solveRec(nums, index+1, target-nums[index]);
//         int ans = include + exclude;
//         return ans;
// }
    
       int solveRec(vector<int>&nums, int index, int target, int currSum){
    if(index==nums.size()){
        if(target==currSum) return 1;
        else return 0;
    }	
        
        int include =solveRec(nums, index+1, target, currSum+nums[index]);
        int exclude =solveRec(nums, index+1, target, currSum-nums[index]);
        int ans = include + exclude;
        return ans;
}
int solveMem(vector<int>&nums, int index, int sum, vector<vector<int>>&dp){
       if(index==0){
           if(sum==0 && nums[0]==0) return 2;
           if(sum==0 || sum==nums[0]) return 1;
           return 0;
       }   
      if(dp[index][sum]!=-1){
          return dp[index][sum];
      }
        int notTake =solveMem(nums, index-1, sum, dp);
        int take=0;
      if(nums[index]<=sum){
          take=solveMem(nums, index-1, sum - nums[index], dp);
      }
    
        int ans = take + notTake;
        return dp[index][sum] = ans;
}
    

    int findTargetSumWays(vector<int>& nums, int target) {
	// //  // approach-1>> Using Recursion 
        int n= nums.size();
	// return solveRec(nums, 0, target, 0);

	// // approach-2>> Using Recursion+Memoization (count of subset with given diff)
        int totalSum=0;
        for(int i=0; i<n;i++){
            totalSum+= nums[i];
        }
      int s1 = (totalSum-target)/2;
        if(target>totalSum || (totalSum-target)%2) return 0;
        vector<vector<int>>dp(n+1, vector<int>(s1+1, -1));
	return solveMem(nums, n-1, s1,  dp);

    }
};