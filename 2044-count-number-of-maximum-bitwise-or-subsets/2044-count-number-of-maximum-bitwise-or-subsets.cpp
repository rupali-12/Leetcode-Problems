class Solution {
public:
    int solveRec(int idx, int currOr, vector<int>nums, int &maxOr){
        if(idx==nums.size()){
            
            if(currOr==maxOr) return 1;
            else return 0;
        }
        
        // Take 
        int takeCount= solveRec(idx+1, currOr | nums[idx], nums, maxOr);
        
         // Not Take 
        int notTakeCount= solveRec(idx+1, currOr, nums, maxOr);
        
        return takeCount + notTakeCount;
    }
     int solveRecMemo(int idx, int currOr, vector<int>nums, int &maxOr, vector<vector<int>>&dp){
        if(idx==nums.size()){
            
            if(currOr==maxOr) return dp[idx][currOr] = 1;
            else return dp[idx][currOr] = 0;
        }
         if(dp[idx][currOr]!=-1){
             return dp[idx][currOr];
         }
        
        // Take 
        int takeCount= solveRecMemo(idx+1, currOr | nums[idx], nums, maxOr, dp);
        
         // Not Take 
        int notTakeCount= solveRecMemo(idx+1, currOr, nums, maxOr, dp);
        
        return dp[idx][currOr] = takeCount + notTakeCount;
    }
    int countMaxOrSubsets(vector<int>& nums) {
         int maxOr =0;
        for(auto n: nums){
            maxOr= maxOr | n;
        }
        int currOr=0;
        
        // // Approach-1: Recursion 
        // return solveRec(0, currOr, nums, maxOr);
        
        // Approach-2: Recursion + Memoization
        vector<vector<int>>dp(nums.size()+1, vector<int>(maxOr+1, -1));
        return solveRecMemo(0, currOr, nums, maxOr, dp);
    }
};