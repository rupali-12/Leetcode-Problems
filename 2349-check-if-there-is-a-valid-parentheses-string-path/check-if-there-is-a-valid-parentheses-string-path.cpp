class Solution {
public:
    int m, n;
    int dp[101][101][201];
    bool solve(int i, int j, vector<vector<char>>& grid, int balance){
        if(i>=m || j>=n) return false;

        // invalid parenthesis prefix
        if(balance<0) return false;

        // current cell
        if(grid[i][j]=='('){
            balance+=1;
        }
        else{
            balance-=1;
        }

    //  invalid after adding current cell
    if(balance<0){
        return false;
    }

    // Already calculated
        if(dp[i][j][balance]!=-1){
            return dp[i][j][balance];
        }

    // destination
    if(i==m-1 && j==n-1){
        return dp[i][j][balance] = (balance==0);
    }

    bool down = solve(i+1, j, grid, balance);
    bool right = solve(i, j+1, grid, balance);
    return dp[i][j][balance]= right || down;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
       m = grid.size(), n= grid[0].size();
       int balance =0;
       memset(dp, -1, sizeof(dp));
       return solve(0, 0, grid, 0);
    }
};



