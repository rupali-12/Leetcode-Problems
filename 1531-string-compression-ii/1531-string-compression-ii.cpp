int dp[101][27][101][101];
class Solution {
public:
    // global 
    // int dp[101][27][101][101];
    int solveRec(int index, int prev, int len, int k, string &s){
        if(k<0) return INT_MAX;
        if(index==s.length()) return 0;
        int del = solveRec(index+1, prev, len, k-1, s);
        int keep=0;
        if((s[index]-'a')==prev){
            // check for len>9 or 99 
            if(len==1 || len==9 || len==99){
                keep+= 1;
            }
            keep += solveRec(index+1, prev, len+1, k, s);
        }
        else{
            keep= 1 + solveRec(index+1, (s[index]-'a'), 1, k, s);
        }
        return min(del, keep);
    }
        int solveMem(int index, int prev, int len, int k, string &s){
        if(k<0) return INT_MAX;
        if(index==s.length()) return 0;
            if(dp[index][prev][len][k]!=-1) return dp[index][prev][len][k];
        int del = solveMem(index+1, prev, len, k-1, s);
        int keep=0;
        if(s[index]-'a'==prev){
            // check for len>9 or 99 
            if(len==1 || len==9 || len==99){
                keep+= 1;
            }
            keep += solveMem(index+1, prev, len+1, k, s);
        }
        else{
            keep= 1 + solveMem(index+1, (s[index]-'a'), 1, k, s);
        }
        return dp[index][prev][len][k] =  min(del, keep);
    }
    

    int getLengthOfOptimalCompression(string s, int k) {
     int prevChar = 26;
     int len= 0;
        
        // // Approach-1: Recursion
        // return solveRec(0, prevChar, len, k, s);
           
        // // Approach-2: Recursion + Memoization
        // [index][prev][len][k]
       
        memset(dp, -1, sizeof(dp));
        return solveMem(0, prevChar, 0, k, s);
    }
};