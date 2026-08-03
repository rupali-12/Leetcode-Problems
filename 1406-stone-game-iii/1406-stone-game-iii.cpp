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

        // // Approach-1 Recursion
        // memset(dp, -1, sizeof(dp));
        // int diff = solve(stoneValue, 0);

        // Approach-2: Bottom up
        vector<int>t(n+1, 0);
        for(int i=n-1; i>=0; i--){
            t[i] = stoneValue[i] - t[i+1];

            if(i+2<=n){    // if(i+1<n && i+2<=n){
              t[i] = max(t[i], (stoneValue[i]+stoneValue[i+1] - t[i+2]));
            }

            if(i+3<=n){    // if(i+1<n && i+2<n && i+3<=n){
              t[i] = max(t[i], (stoneValue[i]+stoneValue[i+1] +stoneValue[i+2] - t[i+3]));
            }
        }
        int diff = t[0];
        if(diff > 0) return "Alice";
        else if(diff < 0) return "Bob";
        else return "Tie";
    }
};