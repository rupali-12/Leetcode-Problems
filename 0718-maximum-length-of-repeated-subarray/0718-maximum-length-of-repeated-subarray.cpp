class Solution {
public:

        int solveRec(vector<int>& nums1, vector<int>& nums2, int i , int j , int cnt){
        if(i==nums1.size() || j==nums2.size()) return cnt;
        
        //match case
        if(nums1[i]==nums2[j]){
            cnt=solveRec(nums1, nums2,i+1,j+1,cnt+1);
        }
        
        //for not match case 
        cnt=max(cnt, max(solveRec(nums1, nums2,i+1,j,0), solveRec(nums1, nums2,i,j+1,0))) ;
        return cnt;
    } 
     int solveTab(vector<int>& nums1, vector<int>& nums2){
        vector<vector<int>>dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
         int ans=0;
         for(int i=1; i<=nums1.size(); i++){
             for(int j=1; j<=nums2.size(); j++){
                 if(nums1[i-1]==nums2[j-1]){    // as 1-based indexing is used
                     dp[i][j]= 1+ dp[i-1][j-1];
                 }
                 else{
                     dp[i][j]=0;
                 }
                 ans= max(ans, dp[i][j]);
             }
         }
         return ans;
    } 
     int solveTabSpOpt(vector<int>& nums1, vector<int>& nums2){
         vector<int>prev(nums2.size()+1, 0);
         vector<int>curr(nums2.size()+1, 0);
         int ans=0;
         for(int i=1; i<=nums1.size(); i++){
             for(int j=1; j<=nums2.size(); j++){
                 if(nums1[i-1]==nums2[j-1]){    // as 1-based indexing is used
                     curr[j]= 1+ prev[j-1];
                 }
                 else{
                     curr[j]=0;
                 }
                 ans= max(ans, curr[j]);
             }
             prev=curr;
         }
         return ans;
    } 
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
                int n=nums1.size(),m=nums2.size();
        // // Approach-1: Recursion
        // // (i, j, count)
        // return solveRec(nums1, nums2, 0, 0, 0);
        
         //  // Approach-2: (Tabulation)
        // return solveTab(nums1, nums2);
        
         // Approach-3: (Tabulation + space optimization)
        return solveTabSpOpt(nums1, nums2);
    }
};