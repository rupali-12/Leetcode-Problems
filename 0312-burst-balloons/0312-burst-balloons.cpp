class Solution {
public:
    int solveRec(vector<int>& nums, int i, int j){
	if(i>j) return 0;
    int maxi= INT_MIN;
	for(int k=i; k<=j; k++){
		int numOfCoins = (nums[i-1]*nums[k]*nums[j+1]) + solveRec(nums, i, k-1)+ solveRec(nums, k+1, j);
		maxi= max(maxi, numOfCoins);
	}
	return maxi;
}
    int solveMem(vector<int>& nums, int i, int j, vector<vector<int>>&dp){
	if(i>j) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
    int maxi= INT_MIN;
	for(int k=i; k<=j; k++){
		int numOfCoins = (nums[i-1]*nums[k]*nums[j+1]) + solveMem(nums, i, k-1, dp)+ solveMem(nums, k+1, j, dp);
		maxi= max(maxi, numOfCoins);
	}
	return dp[i][j]= maxi;
}
    int solveTab(vector<int>&nums, int n){
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int i= n-2; i>=1; i--){
            for(int j=1; j<= n-2; j++){
                if(i>j) continue;
                int maxi= INT_MIN;
                for(int k=i; k<=j; k++){
                    int cost= (nums[i-1] * nums[k]*nums[j+1]) + dp[i][k-1] + dp[k+1][j];
                    maxi= max(maxi, cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n-2];
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n= nums.size();       //  1  2  1 5 4 1 
        int i= 1, j= n-2;
        
        // // Approach-1: Recursion 
        // return solveRec(nums, i, j);
        
        //  // // Approach-2: Recursion + Memoization
        // vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        // return solveMem(nums, i, j, dp);

        // Approach-3: Tabulation 
        return solveTab(nums, n);
    }
};