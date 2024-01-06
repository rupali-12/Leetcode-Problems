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
    
   int solveTab(vector<vector<int>>& event, int n){
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
       for(int index= n-1; index>=0; index--){
           for(int prev= n-1; prev>=-1; prev--){
                int ans;
        int take = event[index][2] + dp[index+1][index+1];
        int notTake = 0 + dp[index+1][prev+1];
        if (prev == -1 || event[prev][1] <= event[index][0]) {
            ans = max(take, notTake);
        } else {
            ans = notTake;
        }
               dp[index][prev+1]=ans;
           }
       }
       return dp[0][0];
   }
      int solveTabSpOpt(vector<vector<int>>& event, int n){
        vector<int>nextRow(n+1, 0);
          vector<int>currRow(n+1, 0);
       for(int index= n-1; index>=0; index--){
           for(int prev= n-1; prev>=-1; prev--){
                int ans;
        int take = event[index][2] + nextRow[index+1];
        int notTake = 0 + nextRow[prev+1];
        if (prev == -1 || event[prev][1] <= event[index][0]) {
            ans = max(take, notTake);
        } else {
            ans = notTake;
        }
               currRow[prev+1]=ans;
           }
           nextRow = currRow;
       }
       return nextRow[0];
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

        // Approach-2: Recursion + Memoization
        vector<int>dp(n, -1);
        return solveMem(event, 0, startTime, n,  dp);
        
//         // Approach-3: Tabulation
//         return solveTab(event, n);
                
        // // Approach-4: Tabulation + space optimization
        // return solveTabSpOpt(event, n);
        
      
        
    }
};