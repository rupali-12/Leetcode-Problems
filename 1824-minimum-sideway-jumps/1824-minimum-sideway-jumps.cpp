class Solution {
public:
    int solveRec(vector<int>& obstacles, int currlane, int currpos){
        int n=obstacles.size()-1;
        if(currpos==n){
            return 0;
        }
         
        // no obstacle in curr lane 
         int ans=INT_MAX;
        if(obstacles[currpos+1]!=currlane){
           return solveRec(obstacles, currlane, currpos+1);
        }
        else{
            // obstacle not in currlane, and case of side jump
            // but we want min ans
            // int ans=INT_MAX;
            for(int i=1; i<=3; i++){
                if(currlane!=i && obstacles[currpos]!=i){
                    // update ans 
                    // add 1 bcoz we already jumped adn make call for recursion 
                    ans =min(ans, 1 + solveRec(obstacles, i, currpos));
                }
            }
              // return ans;
        }
          return ans;
    }
    int solveMem(vector<int>& obstacles, int currlane, int currpos, vector<vector<int>>&dp){
        int n =obstacles.size()-1;
        if(currpos==n){
            return 0;
        }
        if(dp[currlane][currpos]!=-1){
            return dp[currlane][currpos];
        }
        int ans =INT_MAX;
        if(obstacles[currpos+1]!=currlane){
            return solveMem(obstacles, currlane, currpos+1, dp);
        }
        else{
            for(int i=1; i<=3; i++){
                if(currlane!=i && obstacles[currpos]!=i){
                    ans =min(ans, 1+solveMem(obstacles, i, currpos, dp));
                }
            }
            dp[currlane][currpos]=ans;
        }
        return ans;
    }
    int solveTab(vector<int>& obstacles){
        int n=obstacles.size()-1;
          vector<vector<int>>dp(4, vector<int>(obstacles.size(), 1e9));
        // we know that
         dp[0][n]=0;
         dp[1][n]=0;
         dp[2][n]=0;
         dp[3][n]=0;
        
        for(int currpos= n-1; currpos>=0; currpos--){
            for(int currlane=1; currlane<=3; currlane++){
                if(obstacles[currpos+1]!=currlane){
                 dp[currlane][currpos] = dp[currlane][currpos+1];
                }
                else{
                    int ans= 1e9;
                    for(int i=1; i<=3; i++){
                        if(currlane!=i && obstacles[currpos]!=i){
                            ans =min(ans, 1+dp[i][currpos+1]);
                        }
                    }
                dp[currlane][currpos]=ans;
                }
            }
        }
        return min(dp[2][0], min(1+dp[1][0], 1+dp[3][0]));
    }
    int solveSpOpt(vector<int>& obstacles){
        int n=obstacles.size()-1;
      vector<int>curr(4);
        vector<int>next(4);
         next[0]=0;
         next[1]=0;
         next[2]=0;
         next[3]=0;
        
        for(int currpos= n-1; currpos>=0; currpos--){
            for(int currlane=1; currlane<=3; currlane++){
                if(obstacles[currpos+1]!=currlane){
                 curr[currlane] = next[currlane];
                }
                else{
                    int ans= 1e9;
                    for(int i=1; i<=3; i++){
                        if(currlane!=i && obstacles[currpos]!=i){
                            ans =min(ans, 1+next[i]);
                        }
                    }
                curr[currlane]=ans;
                }
                next=curr;
            }
        }
        return min(curr[2], min(1+curr[1], 1+curr[3]));
    }
    int minSideJumps(vector<int>& obstacles) {
        // // Approach-1>. Using Recursion 
        // return solveRec(obstacles, 2, 0);
        
        // // // Approach-2>. Using Recursion +memoization
        // vector<vector<int>>dp(4, vector<int>(obstacles.size(), -1));
        // // dp[lane][position ]
        // return solveMem(obstacles, 2, 0, dp);
        
        //  // // Approach-3>. Using Tabulation
        // return solveTab(obstacles);
        
         // // Approach-4>. Using space optimization
        return solveSpOpt(obstacles);
    }
};