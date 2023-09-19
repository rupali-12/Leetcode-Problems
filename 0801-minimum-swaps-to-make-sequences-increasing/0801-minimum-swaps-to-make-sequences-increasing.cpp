class Solution {
public:
    int solveRec(vector<int>& nums1, vector<int>& nums2, int index, bool swapped){
      if(index==nums1.size()) return 0;
        int ans= INT_MAX;
        int prev1= nums1[index-1];
        int prev2= nums2[index-1];
        
        // catch if swapped is 1 means prev index element is swapped and point to wrong elemet now bcoz it point to wrong eleemnt for nxt eleemnt thsts why i swapped 
        if(swapped){
            swap(prev1, prev2);
        }
        
        // no swap
        if(nums1[index]>prev1 && nums2[index]>prev2){
            ans= solveRec(nums1, nums2, index+1, 0);
        }
        
        // swap 
        if(nums1[index]>prev2 && nums2[index]>prev1){
            ans= min(ans, 1+solveRec(nums1, nums2, index+1, 1));
        }
        return ans;
    }
    int solveMem(vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int>>&dp){
        if(index==nums1.size()) return 0;
        if(dp[index][swapped]!=-1){
            return dp[index][swapped];
        }
        int ans= INT_MAX;
        int prev1= nums1[index-1];
        int prev2= nums2[index-1];
        
        // catch if swapped is 1 means prev index element is swapped and point to wrong elemet now bcoz it point to wrong eleemnt for nxt eleemnt thsts why i swapped 
        if(swapped){
            swap(prev1, prev2);
        }
        
        // no swap
        if(nums1[index]>prev1 && nums2[index]>prev2){
            ans= solveMem(nums1, nums2, index+1, 0, dp);
        }
        
        // swap 
        if(nums1[index]>prev2 && nums2[index]>prev1){
            ans= min(ans, 1+solveMem(nums1, nums2, index+1, 1, dp));
        }
        return dp[index][swapped] = ans;
    }
//     int solveTab(vector<int>& nums1, vector<int>& nums2){
   
//     }
//     int solveSpOpt(vector<int>& nums1, vector<int>& nums2){
//         int n=nums1.size();
//         // f s 
//         // f s
//         // f s
    
//     }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        nums1.insert(nums1.begin(), -1);
         nums2.insert(nums2.begin(), -1);
        // // Approach-1> Using Recursion
        //  bool swapped= false;
        // return solveRec(nums1, nums2, 1, swapped);
     
        
        //  // Approach-2> Using Recursion + Memoization 
        bool swapped= false;
        vector<vector<int>>dp(n+1, vector<int>(3, -1));
        return solveMem(nums1, nums2, 1, swapped, dp);
     
        
        //   // Approach-3> Using Tabulation
        
        
         // Approach-4> Using Space Optimization
      
    }
};