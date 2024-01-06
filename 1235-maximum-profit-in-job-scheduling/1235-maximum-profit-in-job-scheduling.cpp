class Solution {
public:
    int solveRec(vector<vector<int>>& event, int index, vector<int>&startTime, int n) {
        if (index == event.size()) {
            return 0;
        }
       int i= lower_bound(startTime.begin(), startTime.end(), event[index][1])-startTime.begin();
        int take = event[index][2] + solveRec(event, i, startTime, n);
        int notTake = 0 + solveRec(event, index + 1, startTime, n);
      
        return max(take, notTake);
    }

  int solveMem(vector<vector<int>>& event, int index, vector<int>&startTime, int n, vector<int>&dp) {
        if (index == event.size()) {
            return 0;
        }
      if(dp[index]!=-1){
          return dp[index];
      }
       int i= lower_bound(startTime.begin(), startTime.end(), event[index][1])-startTime.begin();
        int take = event[index][2] + solveMem(event, i, startTime, n, dp);
        int notTake = 0 + solveMem(event, index + 1, startTime, n, dp);
      
        return dp[index]= max(take, notTake);
    }
    
   int solveTab(vector<vector<int>>& event, int n, vector<int>startTime){
        vector<int> dp(n+1,  0);
       for(int index= n-1; index>=0; index--){
    int i= lower_bound(startTime.begin(), startTime.end(), event[index][1])-startTime.begin();
        int take = event[index][2] + dp[i];
        int notTake = 0 + dp[index+1];
      
               dp[index]=max(take, notTake);
           }
    
       return dp[0];
   }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> event;
        int mx=INT_MIN;
        for (int i = 0; i < n; i++) {
            mx= max(mx, endTime[i]);
            event.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(event.begin(), event.end());
        sort(startTime.begin(), startTime.end());

        // // Approach-1: Recursion 
        // return solveRec(event, 0, startTime, n);

        // // Approach-2: Recursion + Memoization
        // vector<int>dp(n, -1);
        // return solveMem(event, 0, startTime, n,  dp);
        
        // // Approach-3: Tabulation
        return solveTab(event, n, startTime);
       
        
    }
};