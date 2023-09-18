class Solution {
public:
    int solveRec(vector<int>& nums1, vector<int>& nums2, int index, bool swapped){
        if(index==nums1.size()){
            return 0;
        }
        int ans =INT_MAX;
        int prev1=nums1[index-1];
        int prev2 =nums2[index-1];
        // catch is swapped is 1 then we have to swap prev1 and prev2 
        if(swapped){
            swap(prev1, prev2);
        }
        
        // case of no swap
       if(nums1[index]>prev1 && nums2[index]>prev2){
            ans = solveRec(nums1, nums2, index+1, 0);
        }
        
        // case of swap 
        if(nums1[index]>prev2 && nums2[index]>prev1){
            ans = min(ans, 1+ solveRec(nums1, nums2, index+1, 1));
        }
        return ans;
    }
    int solveMem(vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int>>&dp){
        if(index==nums1.size()){
            return 0;
        }
        if(dp[index][swapped]!=-1){
            return dp[index][swapped];
        }
        int ans =INT_MAX;
        int prev1= nums1[index-1];
        int prev2 = nums2[index-1];
        if(swapped){
            swap(prev1, prev2);
        }
        
        if(nums1[index]>prev1 && nums2[index]>prev2){
            ans = solveMem(nums1, nums2, index+1, 0, dp);
        }
        
    if(nums1[index]>prev2 && nums2[index]>prev1){
        ans = min(ans, 1+ solveMem(nums1, nums2, index+1, 1, dp));
    }
     return dp[index][swapped]=ans;
    }
    int solveTab(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        vector<vector<int>>dp(n+1, vector<int>(2, 0));
        for(int index=n-1; index>=1; index--){
            for(int swapped=1; swapped>=0; swapped--){
                int ans =INT_MAX;
                int prev1=nums1[index-1];
                int prev2 =nums2[index-1];
                if(swapped){
                    swap(prev1, prev2);
                 }
                
                if(nums1[index]>prev1 && nums2[index]>prev2){
                    ans = dp[index+1][0];
                }
                
                if(nums1[index]>prev2 && nums2[index]>prev1){
                    ans = min(ans, 1 + dp[index+1][1]);
                }
                
                dp[index][swapped]=ans;
            }
        }
        return dp[1][0];
    }
    int solveSpOpt(vector<int>& nums1, vector<int>& nums2){
        int n=nums1.size();
        // f s 
        // f s
        // f s
       int swapp=0, noswap=0, currswap=0, currnoswap=0;
        for(int index=n-1; index>=1; index--){
            for(int swapped=1; swapped>=0; swapped--){
                int ans =INT_MAX;
                int prev1= nums1[index-1];
                int prev2 =nums2[index-1];
                if(swapped){
                    swap(prev1, prev2);
                }
                
                if(nums1[index]>prev1 && nums2[index]>prev2){
                    ans = noswap;
                }
                  
                if(nums1[index]>prev2 && nums2[index]>prev1){
                    ans =min(ans, 1+swapp);
                }
                
                if(swapped){
                    currswap=ans;
                }
                else{
                    currnoswap =ans;
                }
            }
            swapp= currswap;
            noswap= currnoswap;
        }
        return min(swapp, noswap);
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
         nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
         // bool swapped=0;
        // // Approach-1> Using Recursion 
        // return solveRec(nums1, nums2, 1, swapped);
        
        //  // Approach-2> Using Recursion + Memoization 
        // int n = nums1.size();
        // vector<vector<int>>dp(n+1, vector<int>(2, -1));
        // return solveMem(nums1, nums2, 1, swapped,dp);
        
        //   // Approach-3> Using Tabulation
        // int n = nums1.size();
        // return solveTab(nums1, nums2);
        
         // Approach-4> Using Space Optimization
        int n = nums1.size();
        return solveSpOpt(nums1, nums2);
    }
};