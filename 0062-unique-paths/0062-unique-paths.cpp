class Solution {
public:
    int solveRec(int m, int n, int startRow, int startCol){
     if(startRow==0 && startCol==0){
		 return 1;
	 }
	 if(startRow<0 || startCol<0){
		 return 0;
	 }
	
	 int ans = solveRec(m, n, startRow-1, startCol)
	  + solveRec(m, n, startRow, startCol-1);
	  return ans;  
}
int solveMem(int m, int n, int startRow, int startCol, vector<vector<int>>&dp){
     if(startRow==0 && startCol==0){
		 return 1;
	 }
	 if(startRow<0 || startCol<0){
		 return 0;
	 }
	 if(dp[startRow][startCol]!=-1){
		 return dp[startRow][startCol];
	 }
	 int ans = solveMem(m, n, startRow-1, startCol, dp)
	  + solveMem(m, n, startRow, startCol-1, dp);
	  return dp[startRow][startCol] = ans;  
}
int solveTab(int m, int n){
	 vector<vector<int>>dp(m, vector<int>(n, 0));
	 dp[0][0]=1;
	 for(int row=0; row<m; row++){
		 for(int col= 0; col<n; col++){
		   if(row==0 && col==0){
			   dp[row][col] = 1;
		   }
		   else{
			   int up=0, left=0;
			   if(row>0){
                 up= dp[row-1][col];
			   }
			   if(col>0){
				   left= dp[row][col-1];
			   }
			   dp[row][col] = up + left;
		   }
		 }
	 }
	 return dp[m-1][n-1];
}
int solveSpOpt(int m, int n){
	vector<int>prev(n, 0);
	for(int row=0; row<m; row++){
		vector<int>curr(n, 0);
		for(int col=0; col<n; col++){
			if(row==0 &&col==0){
				curr[col]=1;
			}
			else{
				int up=0, left=0;
				if(row>0){
					up = prev[col];
				}
				if(col>0){
					left = curr[col-1];
				}
				curr[col]= up+left;
			}
		}
		prev= curr;
	}
	return prev[n-1];
}
    int uniquePaths(int m, int n) {
        // // approach -1 : Reursion 
	// int startRow=m-1, startCol=n-1;
	// return solveRec(m, n, startRow, startCol);

	// // Approach -2: Memoization 
	// vector<vector<int>>dp(m, vector<int>(n, -1));
	// int startRow=m-1, startCol=n-1;
    //  return solveMem(m, n, startRow, startCol, dp);
	
	// // Approach-3> Tabulation
    // return solveTab(m, n);

	// Approach-4> Tabulation + spae optimization 
	return solveSpOpt(m, n);
    }
};