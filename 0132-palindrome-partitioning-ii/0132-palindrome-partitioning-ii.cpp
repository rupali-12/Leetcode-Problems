class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++; j--;
        }
        return true;
    }
    int solveRec(string s, int i){
        if(i==s.length()){
            return 0;
        }
        int mini= INT_MAX;
        for(int k= i; k<=s.length()-1; k++){
         if(isPalindrome(s, i, k)){
            int temp= 1 + solveRec(s, k+1);
            mini= min(mini, temp);
         }
        }
        return mini;
    }
    
    //     // 1nd way -->TLE 
    //  int solveMem(string s, int i,int j,  vector<vector<int>>&dp){
    //     if(i>=j){
    //         return 0;
    //     }
    //      if(isPalindrome(s, i, j)){
    //          return 0;
    //      }
    //       if(dp[i][j]!=-1){
    //           return dp[i][j];
    //       }
    //     int mini= INT_MAX;
    //     for(int k= i; k<=j-1; k++){
    //         int temp= 1 + solveMem(s, i, k, dp) + solveMem(s, k+1, j, dp);
    //         mini= min(mini, temp);
    //      }
    //     return dp[i][j]= mini;
    // }
    
    
    // Memoization-2->optimized 
      int solveMem(string s, int i, vector<int>&dp){
        if(i==s.length()){
            return 0;
        }
          if(dp[i]!=-1){
              return dp[i];
          }
        int mini= INT_MAX;
        for(int k= i; k<=s.length()-1; k++){
         if(isPalindrome(s, i, k)){
            int temp= 1 + solveMem(s, k+1, dp);
            mini= min(mini, temp);
         }
        }
        return dp[i]= mini-1;
    }
    

    

//     // Tabulation way-1 -->TLE
//     int solveTab(string s, int n){
//         vector<vector<int>>dp(n, vector<int>(n, 0));
        
//         for(int i=n-1;i>=0; i--){
//             for(int j=0; j<=n-1; j++){
//                 if(isPalindrome(s, i, j) || i>=j) continue;
//          int mini= INT_MAX;
//         for(int k= i; k<=j-1; k++){
//             int temp= 1 + dp[i][k] + dp[k+1][j];
//             mini= min(mini, temp);
//          }
//                 dp[i][j]= mini;
//             }
//         }
//         return dp[0][n-1];
//     }
    
    // Tabulation way-2 -->  optimized
    int solveTab(string s, int n){
        vector<int>dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            int mini= INT_MAX;
            for(int k=i; k<=n-1; k++){
            if(isPalindrome(s, i, k)){
            int temp= 1 + dp[k+1];
            mini= min(mini, temp);
         }  
            }
            dp[i]=mini;   
          }
        return dp[0]-1;    //  // -1 to avoid last partition which is done at end of string 
    }
    
    int minCut(string s) {
        int i=0;
        // // Approach-1: Recursion 
        // // A|B|C  --> when it do partition after C, it callsfro i==n and return 0 so we need to substract 1 from our ans 
        // return solveRec(s, i)-1;
        
        // // Approach-2: Memoization 
        // vector<int>dp(s.length(), -1);
        // return solveMem(s, i, dp);
        
        // // way-2: 
        // vector<vector<int>>dp(s.length(), vector<int>(s.length(), -1));
        // return solveMem(s, i, s.length()-1, dp);
        
        // // // Approach-3: Tabulation 
        int n= s.length();
        // return solveTab(s, n);
        
        // way-2: 
        return solveTab(s, n);
    }
};



