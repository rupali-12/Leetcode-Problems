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
    int solveTab(vector<int>obst){
        int n= obst.size()-1;
         vector<vector<int>>dp(4, vector<int>(obst.size(), 1e9));
        dp[0][n]=0;
        dp[1][n]=0;
        dp[2][n]=0;
        dp[3][n]=0;
         for(int currpos= n-1; currpos>=0; currpos--){
           for(int currlane = 1; currlane<=3; currlane++){
                if(obst[currpos+1]!=currlane){
                    dp[currlane][currpos] = dp[currlane][currpos+1];
                }
                else{
                    int ans= 1e9+7;
                    for(int i=1; i<=3; i++){
                        if(currlane!=i && obst[currpos]!=i){
                            ans = min(ans, 1 + dp[i][currpos+1]);
                        }
                    }
                    dp[currlane][currpos] = ans;
                }
            }
        }
      
        int res= min(dp[2][0], min(1+dp[1][0], 1+dp[3][0]));
        return res;
    }
     int solveTabSpOpt(vector<int>obst){
        int n= obst.size()-1;
       vector<int>curr(4);
         vector<int>next(4);
        next[0]=0;
        next[1]=0;
         next[2]=0;
         next[3]=0;
         for(int currpos= n-1; currpos>=0; currpos--){
           for(int currlane = 1; currlane<=3; currlane++){
                if(obst[currpos+1]!=currlane){
                    curr[currlane] = next[currlane];
                }
                else{
                    int ans= 1e9+7;
                    for(int i=1; i<=3; i++){
                        if(currlane!=i && obst[currpos]!=i){
                            ans = min(ans, 1 + next[i]);
                        }
                    }
                    curr[currlane] = ans;
                }
            }
             next=curr;
        }
      
        int res= min(next[2], min(1+next[1], 1+next[3]));
        return res;
    }
    int minSideJumps(vector<int>& obst) {
        // // Approach-1: Recursion 
        // return solveRec(obst, 2, 0);
        
        // // Approach-2: Memoization
        // vector<vector<int>>dp(4, vector<int>(obst.size(), -1));
        // return solveMem(obst, 2, 0, dp);
        
        // // Approach-3: Tabulation 
        // int n = obst.size();
        // return solveTab(obst );
        
            // Approach-4: Tabulation + space optimization
        int n = obst.size();
        return solveTabSpOpt(obst );
    }
};

