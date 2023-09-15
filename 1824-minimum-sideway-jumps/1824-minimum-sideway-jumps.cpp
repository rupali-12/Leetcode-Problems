class Solution {
public:
    int solveRec(vector<int>&obst, int currlane, int currpos){
        if(currpos==obst.size()-1) return 0;
        
        // case when there is not obst in currlane
        int ans= INT_MAX;
        for(int i=1; i<=3; i++){
            if(obst[currpos+1]!=currlane){
                return solveRec(obst, currlane, currpos+1);
            }
            else{
                // case of side jump
                if(currlane!=i && obst[currpos]!=i){
                ans =  min(ans, 1 + solveRec(obst, i, currpos));
                }
            }
        }
        return ans;
    }
      int solveMem(vector<int>&obst, int currlane, int currpos, vector<vector<int>>&dp){
        if(currpos==obst.size()-1) return 0;
        
        if(dp[currlane][currpos]!=-1){
            return dp[currlane][currpos];
        }
          
        // case when there is not obst in currlane
        int ans= INT_MAX;
        for(int i=1; i<=3; i++){
            if(obst[currpos+1]!=currlane){
                return dp[currlane][currpos] = solveMem(obst, currlane, currpos+1, dp);
            }
            else{
                // case of side jump
                if(currlane!=i && obst[currpos]!=i){
                ans =  min(ans, 1 + solveMem(obst, i, currpos, dp));
                }
            }
        }
        return dp[currlane][currpos] = ans;
    }
    int minSideJumps(vector<int>& obst) {
        // // Approach-1: Recursion 
        // return solveRec(obst, 2, 0);
        
        // Approach-2: Memoization
        vector<vector<int>>dp(4, vector<int>(obst.size(), -1));
        return solveMem(obst, 2, 0, dp);
    }
};

