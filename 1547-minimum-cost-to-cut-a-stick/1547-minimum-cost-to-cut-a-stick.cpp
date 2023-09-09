class Solution {
public:
    int solveRec(vector<int>&cuts, int i, int j){
        if(i>j){
            return 0;
        }
        
       int mini= INT_MAX;
        for(int ind=i; ind<=j; ind++){
            int cost=( cuts[j+1]-cuts[i-1])%(1000000009) + solveRec(cuts, i, ind-1) + solveRec(cuts, ind+1, j);
            mini= min(mini, cost);
        }
        return mini;
    }
      int solveMem(vector<int>&cuts, int i, int j,  vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
       int mini= INT_MAX;
        for(int ind=i; ind<=j; ind++){
            int cost=( cuts[j+1]-cuts[i-1])%(1000000009) + solveMem(cuts, i, ind-1, dp) + solveMem(cuts, ind+1, j, dp);
            mini= min(mini, cost);
        }
        return dp[i][j]= mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        int i= 1, j= cuts.size()-2;   //   0, 1, 3, 4, 5 , 7  --? j points to 5 which is at index 4 (6-2, here 6 is new size of array)
        
       //  // Approach-1: Recursion 
       // return solveRec(cuts, i, j);
        
        // Approach-2: Moemoization 
        vector<vector<int>>dp(cuts.size()+1, vector<int>(cuts.size()+1, -1));
        return solveMem(cuts, i, j, dp);
        
        
    }
};