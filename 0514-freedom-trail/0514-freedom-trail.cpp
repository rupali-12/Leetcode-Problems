class Solution {
public:
    int m, n;
    int solveRec(string ring, string key, int ptr, int index){
        if(index>=n) return 0;
        
        int ans=INT_MAX;
        for(int i=0; i<m; i++){
            if(ring[i]==key[index]){
                ans = min(ans, min(abs(i-ptr), m-abs(i-ptr)) + 1 + solveRec(ring, key, i, index+1));    // index is index of key 
            }
        }
        
        return ans;
    }
    
     int solveMem(string ring, string key, int ptr, int index, vector<vector<int>>&dp){
        if(index>=n) return 0;
        
         if(dp[ptr][index]!=-1){
             return dp[ptr][index];
         }
        int ans=INT_MAX;
        for(int i=0; i<m; i++){
            if(ring[i]==key[index]){
                ans = min(ans, min(abs(i-ptr), m-abs(i-ptr)) + 1 + solveMem(ring, key, i, index+1, dp));    // index is index of key 
            }
        }
        
        return dp[ptr][index] = ans;
    }
    
    int findRotateSteps(string ring, string key) {
         m= ring.length();
        n= key.length();
        int ptr=0, index=0;
        
        // // Approach-1: Recursion
        // return solveRec(ring, key, ptr, index);
        
         // Approach-2: Recursion + Memoization
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solveMem(ring, key, ptr, index, dp);
    }
};