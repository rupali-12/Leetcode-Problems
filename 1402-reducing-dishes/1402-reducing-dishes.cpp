class Solution {
public:
    int solveRec(vector<int>&satisfaction, int index, int time){
        if(index==satisfaction.size()) return 0;
        
        // include 
        int inc  = satisfaction[index]*(time+1) + solveRec(satisfaction, index+1, time+1);
        // exclude
        int exc = 0 + solveRec(satisfaction, index+1, time);
        int ans = max(inc, exc);
        return ans;
    }
     int solveMem(vector<int>&satisfaction, int index, int time, vector<vector<int>>&dp){
        if(index==satisfaction.size()) return 0;
        if(dp[index][time]!=-1){
            return dp[index][time];
        }
        // include 
        int inc  = satisfaction[index]*(time+1) + solveMem(satisfaction, index+1, time+1, dp);
        // exclude
        int exc = 0 + solveMem(satisfaction, index+1, time, dp);
        int ans = max(inc, exc);
        return dp[index][time] = ans;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        // // Approach-1: Recursion 
        // return solveRec(satisfaction, 0, 0);
        
        // Approach-2: Memoization 
        vector<vector<int>>dp(satisfaction.size(), vector<int>(satisfaction.size(), -1));
        return solveMem(satisfaction, 0, 0, dp);
    }
};