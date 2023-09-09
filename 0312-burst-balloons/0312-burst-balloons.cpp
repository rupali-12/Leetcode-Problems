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
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n= nums.size();       //  1  2  1 5 4 1 
        int i= 1, j= n-2;
        
        // // Approach-1: Recursion 
        // return solveRec(nums, i, j);
        
         // // Approach-2: Recursion + Memoization
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solveMem(nums, i, j, dp);

    }
};