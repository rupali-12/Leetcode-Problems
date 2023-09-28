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
    
   int solveTab(vector<int>&nums, int n, int sum){
       vector<vector<int>>dp(n+1, vector<int>(sum+1, 0));
      if(nums[0]==0)  dp[0][0] = 2;
       else dp[0][0]=1;
      
       if(nums[0]!=0 && nums[0]<=sum) dp[0][nums[0]]=1;
       
       for(int index=1; index<n; index++){
           for(int s = 0; s<=sum;s++){
               int notTake= dp[index-1][s];
               int take=0;
               if(nums[index]<=s){
                   take = dp[index-1][s-nums[index]];
               }
               dp[index][s]= take + notTake;
           }
       }
       return dp[n-1][sum];
   }
    
 
    int findTargetSumWays(vector<int>& nums, int target) {
	// //  // approach-1>> Using Recursion 
        int n= nums.size();
	// return solveRec(nums, 0, target, 0);

        // Approach- subset difference count 
        int totalSum=0;
        for(int i=0; i<n;i++){
            totalSum+= nums[i];
        }
      int s1 = (totalSum-target)/2;
	if(target>totalSum || (totalSum-target)%2) return 0;
        
        // // approach-2>> Using Recursion+Memoization (count of subset with given diff)
	// vector<vector<int>>dp(n+1, vector<int>(s1+1, -1));
	// return solveMem(nums, n-1, s1,  dp);
        
        // Approach-3 Tabulation
        return solveTab(nums, n, s1);
        

    }
};