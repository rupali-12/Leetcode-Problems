class Solution {
public:
   const int mod= 1e9+7;
   typedef long long ll;
   int n;
   ll solveDP(int i, vector<int>&nums, int k, vector<int>&dp){
    if(i>=n){
        return 1;
    }

    if(dp[i]!=-1){
        return dp[i];
    }

    ll count= 0;
    int mx=INT_MIN;
    int mn=INT_MAX;
    for(int j=i; j<n; j++){
         mx= max(mx, nums[j]);
         mn= min(mn, nums[j]);
         if(mx-mn >k){
            break;
         }
         count= (count + solveDP(j+1, nums, k, dp))%mod;
    }
    return dp[i] = count;
   }
    int countPartitions(vector<int>& nums, int k) {
        n= nums.size();
        // // Approach- 1: DP + Memoization
        // vector<int>dp(n, -1);
        // return solveDP(0, nums, k, dp);

// ********************************************************************************************************
        
    //     // Approach-2: Bottom up 
    //     vector<int>dp(n+1,0);
    //    dp[n]=1;
    //     for(int i=n-1; i>=0; i--){
    //         int mx= INT_MIN;
    //         int mn= INT_MAX;
    //         ll count = 0;
    //         for(int j=i; j<n; j++){
    //            mx= max(mx, nums[j]);
    //            mn= min(mn, nums[j]);
    //            if(mx-mn >k){
    //             break;
    //            }
    //            count = (count + dp[j+1])%mod;
    //         }
    //         dp[i] = count;
    //     }
    //     return dp[0];

// ********************************************************************************************************
        
        // Approach 3: optimized approach 
        vector<ll>dp(n+1, 0);
        vector<ll>prefixSum(n+1, 0);
        dp[0] = 1;
        prefixSum[0]=1;
        deque<int>maxdq;
        deque<int>mindq;
        int i=0, j=0;
        while(j<n){

            // maintain max deque
            while(!maxdq.empty() && nums[j] > nums[maxdq.back()]){
                maxdq.pop_back();
            }
            maxdq.push_back(j);
            // maintain min deque
             while(!mindq.empty() && nums[j] < nums[mindq.back()]){
                mindq.pop_back();
            }
            mindq.push_back(j);

            // check invalid window condition 
            while(i<=j && (nums[maxdq.front()] - nums[mindq.front()])>k){
                i++;

                // check deques contain valid i index value 
                if(maxdq.front() < i){
                    maxdq.pop_front();
                }
                if(mindq.front() < i){
                    mindq.pop_front();
                }
            }

            // now have valid window update dp, prefixSum
            dp[j+1] = (prefixSum[j] - (i>0? prefixSum[i-1]:0)+mod)%mod;
            prefixSum[j+1] = (prefixSum[j] + dp[j+1])%mod;
            j++;
        }
            return dp[n];
    }
};