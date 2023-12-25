class Solution {
public:
    int solveRec(string s, int index){
        if(index==s.length()) return 1;
         
        // case of leading 0 
        if(s[index]=='0') return 0;
        
        // case of including single digit 
        int ans = solveRec(s, index+1);
        
        // case of two digits 
        if(index+1 < s.length() && s.substr(index, 2)<="26"){
            ans+= solveRec(s, index+2);
        }
        return ans;
    }
     int solveMem(string s, int index, vector<int>&dp){
        if(index==s.length()) return 1;
         
        // case of leading 0 
        if(s[index]=='0') return 0;
         
         if(dp[index]!=-1) return dp[index];
        
        // case of including single digit 
        int ans = solveMem(s, index+1, dp);
        
        // case of two digits 
        if(index+1 < s.length() && s.substr(index, 2)<="26"){
            ans+= solveMem(s, index+2, dp);
        }
        return dp[index]= ans;
    }
    int numDecodings(string s) {
        
        // // Approach-1: Recursion 
        // return solveRec(s, 0);
        
        // Approach-2: Recursion + Memoization
        vector<int>dp(s.length()+1, -1);
        return solveMem(s, 0, dp);
    }
};