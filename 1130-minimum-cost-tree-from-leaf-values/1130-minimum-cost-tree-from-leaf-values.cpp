class Solution {
public:
    int solveRec(vector<int>&arr, map<pair<int, int>, int>&maxi, int left, int right){
        if(left==right) return 0;
        int ans= INT_MAX;
        for(int i=left; i<right; i++){
            ans= min(ans, (maxi[{left, i}]*maxi[{i+1, right}] + solveRec(arr, maxi, left, i)
                          + solveRec(arr, maxi, i+1, right)));
        }
        return ans;
    }
     int solveMem(vector<int>&arr, map<pair<int, int>, int>&maxi, int left, int right,
                  vector<vector<int>>&dp){
        if(left==right) return 0;
         if(dp[left][right]!=-1){
             return dp[left][right];
         }
        int ans= INT_MAX;
        for(int i=left; i<right; i++){
            ans= min(ans, (maxi[{left, i}]*maxi[{i+1, right}] + solveMem(arr, maxi, left, i, dp)  + solveMem(arr, maxi, i+1, right, dp)));
        }
        return dp[left][right] =ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        // store max
        map<pair<int, int>, int>maxi;
        for(int i=0; i<arr.size(); i++){
            maxi[{i, i}]= arr[i];
            for(int j=i+1; j<arr.size(); j++){
                maxi[{i, j}]= max(maxi[{i, j-1}], arr[j]);
            }
        }
        int n= arr.size();
        
        // // Approach-1: Recursion
        // return solveRec(arr, maxi, 0, n-1);
        
        // Approach-2: Memoization
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solveMem(arr, maxi, 0, n-1, dp);
    }
};