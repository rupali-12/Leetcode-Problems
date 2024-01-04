class Solution {
public:
    int solveRec(vector<int>&nums, int i, int j){
        if(i>j){
            return 0;
        }
        int cost =INT_MIN;
        for(int k=i; k<=j; k++){
            int temp = (nums[i-1]*nums[k]*nums[j+1]) + solveRec(nums, i, k-1) + solveRec(nums, k+1, j);
            cost= max(cost, temp);
        }
        return cost;
    }
    
     int solveMem(vector<int>&nums, int i, int j, vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
         if(dp[i][j]!=-1){
             return dp[i][j];
         }
        int cost =INT_MIN;
        for(int k=i; k<=j; k++){
            int temp = (nums[i-1]*nums[k]*nums[j+1]) + solveRec(nums, i, k-1) + solveRec(nums, k+1, j);
            cost= max(cost, temp);
        }
        return dp[i][j] = cost;
    }
    int solveTab(vector<int>&nums, int n){
       vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int i=n-2; i>=1; i--){
            for(int j=1; j<=n-2; j++){
                if(i>j) continue;
                int cost= INT_MIN;
                for(int k=i; k<=j; k++){
                    int temp = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    cost= max(cost, temp);
                }
                dp[i][j]=cost;
            }
        }
        return dp[1][n-2];
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n= nums.size();
        int i=1, j= n-2;
        
//         // Approach-1 Recursion 
//         return solveRec(nums, i, j);
          
        // // Approach-2 Recursion + Memoization 
        // vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        // return solveMem(nums, i, j, dp);
        
        // Approach-3 Recursion + Memoization 
        return solveTab(nums, n);
    }
};