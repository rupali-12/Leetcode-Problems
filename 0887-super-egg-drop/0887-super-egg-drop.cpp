class Solution {
public:
    int solveRec(int eggs,int floors){
        if(floors==0 || floors==1) return floors;
        if(eggs== 1) return floors;
        int ans= INT_MAX;
        for(int k= 1; k<=floors; k++){
            // max is bcoz to find worst case thn find min sttempts in worst case 
            int temp= 1 + max(solveRec(eggs-1, k-1), solveRec(eggs, floors-k));   
            ans= min(ans, temp);
        }
        return ans;
    }
    
      int solveMem(int eggs,int floors,vector<vector<int>>&dp){
        if(floors==0 || floors==1) return floors;
        if(eggs== 1) return floors;
          
          if(dp[eggs][floors]!=-1){
              return dp[eggs][floors];
          }
        int ans= INT_MAX;
        for(int k= 1; k<=floors; k++){
            // max is bcoz to find worst case thn find min sttempts in worst case 
            int temp= 1 + max(solveMem(eggs-1, k-1, dp), solveMem(eggs, floors-k, dp));   
            ans= min(ans, temp);
        }
        return dp[eggs][floors]= ans;
    }
    
      int optimized(int eggs,int floors,vector<vector<int>>&dp){
        if(floors==0 || floors==1) return floors;
        if(eggs== 1) return floors;
          
          if(dp[eggs][floors]!=-1){
              return dp[eggs][floors];
          }
        int ans= INT_MAX;
          int l=1, h=floors, temp=0;
          while(l<=h){
              int k= l+(h-l)/2;
              int low= optimized(eggs-1, k-1, dp);    // broken so need to come down
              int high = optimized(eggs, floors-k, dp);   // not broken so we need to go up
               temp= 1+ max(high, low);
              if(low<high){
                  l = k+1;
              }
              else{
                  h = k-1;
              }
              ans= min(ans, temp);
          }
       
        return dp[eggs][floors]= ans;
    }
   
    int superEggDrop(int k, int n) {
        // k- number of eggs 
        // n- floors 
        
        // // Approach 1: Recursion
        // return solveRec(k, n);
        
        // //  // Approach 2: Recursion + memoization 
        // vector<vector<int>>dp(k+1, vector<int>(n+1, -1));
        // return solveMem(k, n, dp);
        
        //  // Approach 2: Recursion + memoization 
        vector<vector<int>>dp(k+1, vector<int>(n+1, -1));
        return optimized(k, n, dp);
        
    }
};