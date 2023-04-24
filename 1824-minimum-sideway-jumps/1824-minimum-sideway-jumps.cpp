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
    int minSideJumps(vector<int>& obstacles) {
        // // Approach-1>. Using Recursion 
        // return solveRec(obstacles, 2, 0);
        
        // // Approach-2>. Using Recursion +memoization
        vector<vector<int>>dp(4, vector<int>(obstacles.size(), -1));
        // dp[lane][position ]
        return solveMem(obstacles, 2, 0, dp);
    }
};