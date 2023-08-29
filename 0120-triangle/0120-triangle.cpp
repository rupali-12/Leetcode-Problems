class Solution {
public:
    int solveRec(vector<vector<int>>& triangle, int startRow, int startCol, int n){
	if(startRow==n-1){
		return triangle[startRow][startCol];
	}

	int down = triangle[startRow][startCol]+solveRec(triangle, startRow+1, startCol, n);
	int diag = triangle[startRow][startCol]+solveRec(triangle, startRow+1, startCol+1, n);
	return min(down, diag);
}
int solveMem(vector<vector<int>>& triangle, int startRow, int startCol, int n, vector<vector<int>>&dp){
	if(startRow==n-1){
		return triangle[startRow][startCol];
	}
    if(dp[startRow][startCol]!=-1){
		return dp[startRow][startCol];
	}
	int down = triangle[startRow][startCol]+solveMem(triangle, startRow+1, startCol, n,dp);
	int diag = triangle[startRow][startCol]+solveMem(triangle, startRow+1, startCol+1, n, dp);
	return dp[startRow][startCol]= min(down, diag);
}
int solveTab(vector<vector<int>>&triangle, int n){
	vector<vector<int>>dp(n, vector<int>(n,0));

	// Base case in which i fill last row as such 
	for(int i=0; i<n; i++){
      dp[n-1][i] = triangle[n-1][i];
	}

	// process remaining rows 
	// 0-> 0
	// 1-> 0 1
	// 2-> 0 1 2
	// 3-> 0 1 2 3
	// // means when row = n-2, col = (n-2 to n>=0)

	for(int row=n-2; row>=0; row--){
		for(int col=row; col>=0; col--){
				int down = triangle[row][col] + dp[row+1][col];
				int diag = triangle[row][col] + dp[row+1][col+1];
				dp[row][col] = min(down, diag);
		}
	}
	return dp[0][0];
}
int solveSpOpt(vector<vector<int>>&triangle, int n){
	vector<int>next(n, 0);
	// Base case
	for(int i=0;i<n; i++){
       next[i] = triangle[n-1][i];
	}

	// process remaining cases 
	for(int row= n-2; row>=0; row--){
		vector<int>curr(n, 0);
		for(int col= row; col>=0; col--){
			int down = triangle[row][col] + next[col];
			int diag= triangle[row][col] + next[col+1];
			curr[col] = min(down, diag);
		}
		next= curr;
	}
	return next[0];
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        // // Approach -1: Recursion 
	// int startRow= 0, startCol=0;
	// return solveRec(triangle, startRow, startCol, n);

	// // // Approach -2: Recursion + Memoization
	// int startRow= 0, startCol=0;
	// vector<vector<int>>dp(n, vector<int>(n, -1));
	// return solveMem(triangle, startRow, startCol, n, dp);

	// Approach-3: Tabulation 
	// return solveTab(triangle, n);

	// Approach-4 Space optimization 
	return solveSpOpt(triangle, n);
    }
};