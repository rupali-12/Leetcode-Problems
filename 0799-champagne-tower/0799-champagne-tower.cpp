class Solution {
public:
    double dp[101][101];
    double solve(int poured, int i, int j){
        if(i<0 || j<0 || i<j)
           return 0.0;

        if(i==0 && j==0){   // reached top glass
           return dp[i][j] = poured;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        double upper_left = (solve(poured, i-1, j-1)-1)/2.0;
        double upper_right = (solve(poured, i-1, j)-1)/2.0;
        if(upper_left < 0)
           upper_left =0.0;
        if(upper_right < 0)
           upper_right =0.0;

        return dp[i][j] = upper_left + upper_right;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        // // Approach 1- Recursion + Memoization
        // for(int i=0; i<101; i++){
        //     for(int j=0; j<101; j++){
        //         dp[i][j] =-1;
        //     }
        // }
        // return min(1.0, solve(poured, query_row, query_glass));

        // Approach -2: Tabulation
        double t[101][101]={0.0};
        t[0][0]=poured;
        for(int i=0; i<query_row; i++){
            for(int j=0; j<=i; j++){
                if(t[i][j]>1.0){
                    double overflow = (t[i][j]-1.0)/2.0;
                    t[i+1][j] +=overflow;
                    t[i+1][j+1] +=overflow;
                }
            }
        }
        return min(1.0, t[query_row][query_glass]);
    }
};