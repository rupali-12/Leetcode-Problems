class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long dp[2005][1005];

    long long solve(int n, int r) {
        if (r > n)
            return 0;

        // C(n,r) = C(n,n-r)
        r = min(r, n - r);

        // C(n,0) = 1
        if (r == 0)
            return 1;

        if (dp[n][r] != -1)
            return dp[n][r];

        long long take = solve(n - 1, r - 1);
        long long skip = solve(n - 1, r);

        return dp[n][r] = (take + skip) % MOD;
    }

    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));

        return solve(n + k - 1, 2 * k);
    }
};