class Solution {
public:
     int changesToMakePalindrome(string &s, int i, int j){
         if(j<i){
             return 0;
         }
         int ans=0;
        while(i<j){
            if(s[i]!=s[j]){
             ans++;
            }
            i++; j--;
        }
        return ans;
    }
    bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]){
               return false;
            }
            i++; j--;
        }
        return true;
    }
    int solveRec(string &s, int k, int i, int j){
        // base cases 
        if(i>j) {    //  length=0 
            if(k<=0){     
                return 0;
            }
            else{      // k>0 and len=0 so not possible to break 
                return 99999;   
            }
        }
        
        // 2nd base case when len ==k 
        if(j-i+1 ==k) return 0;   
        
        // 3rd base case when len <k 
        if(j-i+1 <k){
            return 99999;
        }
        
        // if k==1 then check number of changes to amke it palindrome 
        if(k==1) {
            int numChanges = changesToMakePalindrome(s, i, j);
            return numChanges;
        }
        
        int mini= 99999;
        for(int ind=i; ind<=j; ind++){
            int left= solveRec(s, 1, i, ind);
            int right= solveRec(s, k-1, ind+1, j);
            int temp= (left+right);
            mini= min(mini, temp);
        }
        return mini;
    }
     int solveMem(string &s, int k, int i, int j, vector<vector<vector<int>>>&dp){
        // base cases 
        if(i>j) {    //  length=0 
            if(k<=0){     
                return  0;
            }
            else{      // k>0 and len=0 so not possible to break 
                return 99999;   
            }
        }
        
        // 2nd base case when len ==k 
        if(j-i+1 ==k) {
             dp[i][j][k]=  0;
            return 0;
        }   
        
        // 3rd base case when len <k 
        if(j-i+1 <k){
            return 99999;
        }
        
        // if k==1 then check number of changes to amke it palindrome 
        if(k==1) {
            int numChanges = changesToMakePalindrome(s, i, j);
             dp[i][j][k]= numChanges;
            return numChanges;
        }
         if(dp[i][j][k]!=-1){
             return dp[i][j][k];
         }
        
        int mini= 99999;
        for(int ind=i; ind<=j; ind++){
            int left= solveMem(s, 1, i, ind, dp);
            int right= solveMem(s, k-1, ind+1, j, dp);
            int temp= (left+right);
            mini= min(mini, temp);
        }
        return dp[i][j][k]= mini;
    }
    
    // Optimized Approach 
       bool optimizedApp(string &s, int i, int size, int k, vector<vector<int>>&dp){
        // base cases 
       if(i>size){
           return false;
       }
        // if k==1 then check number of changes to amke it palindrome 
        if(k==1) {
           // if(isPalindrome(s, i, size)) return true;
             if(changesToMakePalindrome(s, i, size)==0) return true;
            else return false;
        }
         if(dp[i][k]!=-1){
             return dp[i][k];
         }
        
       bool ans=false;
        for(int j=i; j<=size; j++){
           // if(isPalindrome(s, i, j)){   // less time
            if(changesToMakePalindrome(s, i, j)==0){  // more time
               ans = ans || optimizedApp(s, j+1, size, k-1, dp);
           }
        }
        return dp[i][k]= ans;
    }
   
    
    bool checkPartitioning(string s) {
        int n= s.length();
        int i=0, j= n-1;
        int k=3;   // Number of parts
        int ans;
        
        // // Approach-1: Recursion
        // ans= solveRec(s, k, i, j);
        
        // // // Memoization
        // vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(k+1, -1)));
        // ans= solveMem(s, k, i, j, dp);

        // if(ans==0){
        //     return true;
        // }
        // return false;
        vector<vector<int>>dp(n, vector<int>(k+1, -1));
        return optimizedApp(s, 0, n-1, k, dp);
    }
};