class Solution {
public:
    int solveTab(string s1, string s2, int n, int m, vector<vector<int>>&dp){
	for(int i=1;i<=n; i++){
		for(int j=1; j<=m; j++){
			if(s1[i-1]==s2[j-1]){
				  dp[i][j]= 1 + dp[i-1][j-1];
			}
			else{
               dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
}
    string solve(string str1, string str2){
        int m= str1.length(), n= str2.length();
        vector<vector<string>>dp(m+1, vector<string>(n+1, ""));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + str1[i-1];
                }
                else{
                    dp[i][j]+= dp[i-1][j].size() > dp[i][j-1].size() ? dp[i-1][j]:dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
    string shortestCommonSupersequence(string str1, string str2) {
        
	// // Approach-1:Tabualtion 
	vector<vector<int>>dp(str1.length()+1, vector<int>(str2.length()+1, 0));
	solveTab(str1, str2, str1.length(), str2.length(), dp);
	string s="";
	int i=str1.length(), j=str2.length();
	while(i>0 && j>0){
		if(str1[i-1]==str2[j-1]){
          s.push_back(str1[i-1]);
		  i--; j--;
		}
		else{
           if(dp[i-1][j]>dp[i][j-1]){
               s.push_back(str1[i-1]);
			   i--;
		   }
		   else{
               s.push_back(str2[j-1]);
			   j--;
		   }
		}
	}
        // print is there is any remaining element in both string
        while(i>0){
            s.push_back(str1[i-1]);
            i--;
        }
         while(j>0){
            s.push_back(str2[j-1]);
            j--;
        }
        
	reverse(s.begin(), s.end());
	return s;
        
        
        // Approach-2: optimized
        // string lcs = solve(str1, str2);
        // return lcs;
    }

};