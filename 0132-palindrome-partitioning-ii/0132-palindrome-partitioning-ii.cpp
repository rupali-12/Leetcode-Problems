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
            int temp= 1 + solveRec(s, k+1);
            mini= min(mini, temp);
         }
        }
        return dp[i]= mini-1;
    }
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
        
        // // Approach-3: Tabulation 
        int n= s.length();
        return solveTab(s, n);
        
        
    }
};



