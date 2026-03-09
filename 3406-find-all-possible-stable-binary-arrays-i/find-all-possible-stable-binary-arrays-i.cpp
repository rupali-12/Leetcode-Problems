class Solution {
public:
    int dp[201][201][2];
    int mod = 1e9+7;
    int solve(int zeroLeft, int oneLeft, bool lastWithOne, int limit){
        if(zeroLeft == 0 && oneLeft==0) return 1;
        long long result = 0;
        if(dp[zeroLeft][oneLeft][lastWithOne]!=-1){
            return dp[zeroLeft][oneLeft][lastWithOne];
        }
        if(lastWithOne){   // turn for zero
           for(int len=1; len<= min(limit, zeroLeft); len++){
            result= (result + solve(zeroLeft-len, oneLeft, false, limit))%mod;
           }
        }
        else{
            for(int len=1; len<= min(limit, oneLeft); len++){
            result= (result+ solve(zeroLeft, oneLeft-len, true, limit))%mod;
           }
        }
        return dp[zeroLeft][oneLeft][lastWithOne] = result;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        // // Approach 1: Recursion
        // int startWithZero = solve(zero, one, true, limit);
        // int startWithOne = solve(zero, one, false, limit);
        // return startWithZero + startWithOne;

        // Approach 2: Recursion + Memoization 
       memset(dp, -1, sizeof(dp));
        int startWithZero = solve(zero, one, true, limit);
        int startWithOne = solve(zero, one, false, limit);
        return (startWithZero + startWithOne)%mod;
    }
};