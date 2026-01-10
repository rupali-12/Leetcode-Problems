class Solution {
public:
    int m, n;
    vector<vector<int>>dp;
    int solve(int i, int j, string &s1, string &s2){
       if(i>=m && j>=n){
        return 0;
       }

       if(dp[i][j] != -1){
         return dp[i][j];
       }

    // case s1 end only
       if(i>=m){
          return dp[i][j] = s2[j] + solve(i, j+1, s1, s2);
       }
       else if(j>=n){   // case s2 end only
          return dp[i][j] = s1[i] + solve(i+1, j, s1, s2);
       }

    //  case ith and jth char both are equal
        if(s1[i]==s2[j]){
            return dp[i][j] = solve(i+1, j+1, s1, s2);
        }

        // case when both char not equal 
        int delete_i = s1[i] + solve(i+1, j, s1, s2);
        int delete_j = s2[j] + solve(i, j+1, s1, s2);
        return dp[i][j] = min(delete_i, delete_j);
    }

    int minimumDeleteSum(string s1, string s2) {
        m = s1.length();
        n = s2.length();
        dp.assign(m+1, vector<int>(n+1, -1));
        return solve(0, 0, s1, s2);
    }
};