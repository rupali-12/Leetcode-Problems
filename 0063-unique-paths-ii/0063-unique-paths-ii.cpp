class Solution {
public:
    int mod= (int)(1e9+7);
int solveRec(int startRow, int startCol,vector< vector< int> > &mat){
     if(startRow>=0 && startCol>=0 && mat[startRow][startCol]==1){
		 return 0;
	 }
	 if(startRow==0 && startCol==0){
		 return 1;
	 }
	 if(startRow<0 || startCol<0){
		 return 0;
	 }
	
	 int ans = solveRec(startRow-1, startCol, mat)
	  + solveRec(startRow, startCol-1, mat);
	  return ans;  
}
int solveMem(int startRow, int startCol, 
vector<vector<int>>&dp, vector< vector< int> > &mat){
	if(startRow>=0 && startCol>=0 && mat[startRow][startCol]==1){
		 return 0;
	 }
     if(startRow==0 && startCol==0){
		 return 1;
	 }
	 if(startRow<0 || startCol<0){
		 return 0;
	 }
	 if(dp[startRow][startCol]!=-1){
		 return dp[startRow][startCol];
	 }
	 int ans = solveMem(startRow-1, startCol, dp, mat)
	  + solveMem(startRow, startCol-1, dp, mat);
	  return dp[startRow][startCol] = ans;  
}
int solveTab(int n, int m,vector< vector< int> > &mat){
	// n-row  m- col
	 vector<vector<int>>dp(n, vector<int>(m, 0));
	 dp[0][0]=1;
	 for(int row=0; row<n; row++){
		 for(int col= 0; col<m; col++){
		   if(row==0 && col==0){
			   dp[row][col] = 1;
		   }
		   else{
			   int up=0, left=0;
			   if(mat[row][col]!=1){
				   if(row>0){
                 up= dp[row-1][col];
			   }
			   if(col>0){
				   left= dp[row][col-1];
			   }
			   }
			   dp[row][col] = (up + left)%mod;
		   }
		 }
	 }
	 return dp[n-1][m-1]%mod;
}
int solveSpOpt(int n, int m,vector< vector< int> > &mat ){
	// m- col 
	vector<int>prev(m, 0);
	for(int row=0; row<n; row++){
		vector<int>curr(m, 0);
		for(int col=0; col<m; col++){
			// if(mat[row][col]==-1){
			// 	curr[col]=0;
			// }
			if(row==0 &&col==0){
				curr[col]=1;
			}
			else{
				int up=0, left=0;
				if(mat[row][col]!=1){
                    if(row>0){
					up = prev[col];
				}
				if(col>0){
					left = curr[col-1];
				}
                }
				curr[col]= (up+left)%mod;
			}
		}
		prev= curr;
	}
	return prev[m-1];
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
          // // approach -1 : Recursion 
        int n = obstacleGrid.size();
        int m= obstacleGrid[0].size();
	// int startRow=n-1, startCol=m-1;
	// return solveRec(startRow, startCol,obstacleGrid);

	// // Approach -2: Memoization 
	vector<vector<int>>dp(n, vector<int>(m, -1));
	int startRow=n-1, startCol=m-1;
     return solveMem(startRow, startCol, dp,obstacleGrid);
	
	// // Approach-3> Tabulation
    // return solveTab(n, m, obstacleGridmat);

	// Approach-4> Tabulation + spae optimization 
	// return (solveSpOpt(n, m, obstacleGrid));
    }
};