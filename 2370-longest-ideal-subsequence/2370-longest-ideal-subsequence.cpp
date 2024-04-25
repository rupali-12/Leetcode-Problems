class Solution {
public:
    
    int solveRec(string s, int curr, int prev, int k){
        if(curr>=s.length())return 0;
        
        int take=0, nottake=0;
        if(prev==0 || (abs(prev-(s[curr]-'a'+1))<=k)){    // +1 is not necessary but in both places 
            take= 1+ solveRec(s, curr+1, (s[curr]-'a'+1), k);
        }
         nottake= solveRec(s, curr+1, prev,k);
        return max(take, nottake);
    }
    
     int solveMem(string s, int curr, int prev, int k, vector<vector<int>>&dp){
        if(curr>=s.length())return 0;
        
         if(dp[curr][prev]!=-1) return dp[curr][prev];
        int take=0, nottake=0;
        if(prev==0 || (abs(prev-(s[curr]-'a'+1))<=k)){    // +1 is not necessary but in both places 
            take= 1+ solveMem(s, curr+1, (s[curr]-'a'+1), k, dp);
        }
         nottake= solveMem(s, curr+1, prev,k, dp);
        return dp[curr][prev] =  max(take, nottake);
    }
    
      int solveTab(string s, int k, vector<int>&dp){
          int result=0;
       for(int curr=0; curr<s.length(); curr++){
           for(int prev= curr-1; prev>=0; prev--){

        if(abs(s[curr]-s[prev])<=k){    
           dp[curr] = max(dp[curr], dp[prev]+1);
        }
           }
        result= max(result, dp[curr]);
       }
        return result;
    }
    
    int longestIdealString(string s, int k) {
        // // Approach-1: Recursion 
        // int curr=0, prev=0;
        // return solveRec(s, curr, prev, k); 
        
        //  // Approach-2: Recursion + Memoization
        // int curr=0, prev=0;
        // vector<vector<int>>dp(s.length()+1, vector<int>(27, -1));
        // return solveMem(s, curr, prev, k, dp);
        
        //  // Approach-3: Bottom up
        // vector<int>dp(s.length(), 1);  // current char will always be a part of subsequence
        // return solveTab(s, k, dp);
        
        // Approach-4: Optimized
        vector<int>dp(26, 0);
        int result=0;
        int n= s.length();
        
        for(int i=0; i<n; i++){
            int curr= s[i]-'a';
            int left= max(0, curr-k);
            int right = min(25, curr+k);
            int longest=0;
            for(int j=left; j<=right; j++){
                longest = max(longest, dp[j]);
            }
            dp[curr] = max(dp[curr], longest+1);
            result= max(result, dp[curr]);
        }
        return result;
    }
};