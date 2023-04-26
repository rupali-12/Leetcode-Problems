class Solution {
public:
    int solveRec(vector<int>& satisfaction, int i,int time){
        if(i==satisfaction.size()){
            return 0;
        }
        
        // case of include
        // int include =satisfaction[i]*time +  solveRec(satisfaction, i+1, time+1);
         int include =satisfaction[i]*(time+1) +  solveRec(satisfaction, i+1, time+1);
        // case of exclude 
        int exclude = solveRec(satisfaction, i+1, time);
        
        return max(include, exclude);
    }
    int solveMem(vector<int>& satisfaction, int i, int time, vector<vector<int>>&dp){
        if(i==satisfaction.size()){
            return 0;
        }
        if(dp[time][i]!=-1){
            return dp[time][i];
        }
        int include =satisfaction[i]*time +solveMem(satisfaction, i+1,time+1, dp);
        int exclude =solveMem(satisfaction, i+1, time, dp);
          
       dp[time][i] =max(include, exclude);
        return dp[time][i];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        
        // // Approach-1> Using Recursion 
        //  return solveRec(satisfaction, 0, 1);
        //  return solveRec(satisfaction, 0, 0);
        
         // Approach-2> Using Recursion +Memoization 
        int n =satisfaction.size();
        vector<vector<int>>dp(n+2,vector<int>(n+1, -1));
         return solveMem(satisfaction, 0, 1,dp);
    }
};