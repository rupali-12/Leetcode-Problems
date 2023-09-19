class Solution {
public:
//       // Approach-1-> Top down 
//     int solveRec(int index, int currDiff, vector<int>&nums){
//         if(index<0) return 0;
//         int ans=0;
//         for(int j= index-1; j>=0; j--){
//             if(nums[index]-nums[j] ==currDiff){
//                 ans= max(ans, 1+ solveRec(j, currDiff, nums));
//             }
//         }
//         return ans;
//     }
//      int solveMem(int index, int diff, vector<int>&nums, unordered_map<int, int>dp[]){
//         if(index<0) return 0;
//          if(dp[index].count(diff)){
//              return dp[index][diff];
//          }
//         int ans=0;
//         for(int j= index-1; j>=0; j--){
//             if(nums[index]-nums[j] ==diff){
//                 ans= max(ans, 1+ solveMem(j, diff, nums, dp));
//             }
//         }
//         return dp[index][diff] = ans;
//     }
//     int longestArithSeqLength(vector<int>& nums) {
// //         // Approach-1-i  Recursion
// //         int n= nums.size();
// //            if(n<=2) return n;
        
// //         int ans=0;
// //         for(int i=0; i<n; i++){
// //             for(int j=i+1; j<n; j++){
// //                 int currDiff = nums[j]- nums[i];
// //                ans = max(ans, 2 + solveRec(i, currDiff, nums));     
// //             }
// //         }
// //         return ans;
        
//         // Approach-1-ii  Memoization
//         int n= nums.size();
//         unordered_map<int, int>dp[n+1];
//            if(n<=2) return n;
        
//         int ans=0;
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 int currDiff = nums[j]- nums[i];
//                ans = max(ans, 2 + solveMem(i, currDiff, nums, dp));     
//             }
//         }
//         return ans;
//     }
    
    // *****************************************************************
    // Approach-2: Bottom up 
    int longestArithSeqLength(vector<int>& nums) {
     int n= nums.size();
        if(n<=2) return n;
        unordered_map<int, int>dp[n+1];
        int ans=0;
        for(int i= 1; i<n; i++){
            for(int j=0; j<i; j++){
                int diff = nums[i]- nums[j];
                int cnt=1;   // included element ith index
                
                // check if ans already exist or not 
                if(dp[j].count(diff)){
                    cnt= dp[j][diff];
                }
                
                // update ans of ith index 
                dp[i][diff] = 1 +cnt;
                
                // update ans 
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};