class Solution {
public:
    int n;
    int dp[50001];
    int solve(vector<int>&stoneValue, int i){
        if(i>=n) return 0;
        if(dp[i] !=-1) return dp[i];
        int take_1 = stoneValue[i] - solve(stoneValue, i+1);
        int take_2= INT_MIN;
        if(i+1 < n){
            take_2 = stoneValue[i] + stoneValue[i+1] - solve(stoneValue, i+2);
        }
        int take_3 = INT_MIN;
        if(i+2 < n){
            take_3 = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - solve(stoneValue, i+3);
        }
        return dp[i] = max(take_1, max(take_2, take_3));
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        memset(dp, -1, sizeof(dp));
        int diff = solve(stoneValue, 0);
        if(diff > 0) return "Alice";
        else if(diff < 0) return "Bob";
        else return "Tie";
    }
};