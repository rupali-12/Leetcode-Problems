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
         int solveTab(vector<int>&satisfaction,int n){
  vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
             int time=0;
             // index=0, time= 1 (if include) ans 0 if(not included)
       for(int index= n-1; index>=0; index--){
        for(int time= index; time>=0; time--){
             // include 
        int inc  = satisfaction[index]*(time+1) + dp[index+1][time+1];
        // exclude
        int exc = 0 + dp[index+1][time];
        dp[index][time] = max(inc, exc);
        }
       }
        return dp[0][0];
    }
      int solveTabSpOpt(vector<int>&satisfaction,int n){
          vector<int>curr(n+1, 0);
          vector<int>next(n+1, 0);
      // index=0, time= 1 (if include) ans 0 if(not included)
       for(int index= n-1; index>=0; index--){
        for(int time= index; time>=0; time--){
             // include 
        int inc  = satisfaction[index]*(time+1) + next[time+1];
        // exclude
        int exc = 0 + curr[time];
        curr[time] = max(inc, exc);
        }
           next=curr;
       }
        return next[0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        // // Approach-1: Recursion 
        // return solveRec(satisfaction, 0, 0);
        
        // // Approach-2: Memoization 
        // vector<vector<int>>dp(satisfaction.size(), vector<int>(satisfaction.size(), -1));
        // return solveMem(satisfaction, 0, 0, dp);
        
        // // Approach-3: Tabulation 
        // return solveTab(satisfaction, satisfaction.size());
        
        // Approach-4: Tabulation + space optimization 
        return solveTabSpOpt(satisfaction, satisfaction.size());
    }
};