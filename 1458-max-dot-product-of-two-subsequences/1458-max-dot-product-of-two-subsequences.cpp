class Solution {
public:
    int m, n;
    int dp[501][501];
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j){
        if(i==m || j==n){
            return -1e9;
        }

        if(dp[i][j]!= -1e9){
            return dp[i][j];
        }

        int val = nums1[i]*nums2[j];
        int take_i_j = nums1[i]*nums2[j] + solve(nums1, nums2, i+1, j+1);
        int take_i = solve(nums1, nums2, i, j+1);   // take i and skip j
        int take_j = solve(nums1, nums2, i+1, j);   // take j and skip i
        return dp[i][j] = max(val, max(take_i_j, max(take_i, take_j)));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        for(int i=0; i<501; i++){
            for(int j=0; j<501; j++){
                dp[i][j] = -1e9;
            }
        }
        return solve(nums1, nums2, 0, 0);
    }
};