class Solution {
public:
        
int solveRec(vector<int> &num, int tar){
   if(tar==0) return 1;
   if(tar<0) return 0;

   int ans=0;
   for(int i=0; i<num.size(); i++){
       ans+= solveRec(num, tar- num[i]);
   }
   return ans;
}

int solveMem(vector<int>&num, int tar, vector<unsigned>&dp){
   if(tar==0) return 1;
   if(tar<0) return 0;
    if(dp[tar]!=-1){
        return dp[tar];
    }
   int ans=0;
   for(int i=0; i<num.size(); i++){
       ans+= solveMem(num, tar- num[i],dp);
   }
   return dp[tar] = ans;
}
int solveTab(vector<int>&num, int tar){
    vector<unsigned>dp(tar+1, 0);
    dp[0]=1;
    for(int t= 1; t<=tar; t++){
        int ans=0;
        for(int i=0; i<num.size(); i++){
           if(t-num[i]>=0){
               ans+= dp[t-num[i]];
           }
        }
        dp[t] = ans;
    }
    return dp[tar];
}
    int combinationSum4(vector<int>& num, int tar) {
         // // Approach-1>> USing Recursion 
    // return solveRec(num, tar);

    // // Approach-2>> Using Memoization 
    // vector<unsigned>dp(tar+1, -1);
    // return solveMem(num, tar, dp);

    // Approach-3>> USing Tabulation 
    return solveTab(num, tar);
    }
};