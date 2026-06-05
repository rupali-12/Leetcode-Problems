class Solution {
public:

    struct Node {
        long long cnt;
        long long wave;
    };

    string s;

    Node dp[20][2][2][11][11];
    bool vis[20][2][2][11][11];

    Node solve(int pos,
               int tight,
               int started,
               int prev1,
               int prev2)
    {
        if(pos == s.size())
            return {1,0};

        if(vis[pos][tight][started][prev1+1][prev2+1])
            return dp[pos][tight][started][prev1+1][prev2+1];

        vis[pos][tight][started][prev1+1][prev2+1] = true;

        Node ans = {0,0};

        int lim = tight ? s[pos]-'0' : 9;

        for(int d=0; d<=lim; d++)
        {
            int ntight = tight && (d==lim);

            if(!started && d==0)
            {
                Node child =
                    solve(pos+1, ntight, 0, -1, -1);

                ans.cnt += child.cnt;
                ans.wave += child.wave;
            }
            else
            {
                int extra = 0;

                if(prev2!=-1 && prev1!=-1)
                {
                    if((prev1 > prev2 && prev1 > d) ||
                       (prev1 < prev2 && prev1 < d))
                        extra = 1;
                }

                Node child =
                    solve(pos+1,
                          ntight,
                          1,
                          d,
                          prev1);

                ans.cnt += child.cnt;
                ans.wave += child.wave
                          + 1LL * extra * child.cnt;
            }
        }

        return dp[pos][tight][started][prev1+1][prev2+1] = ans;
    }

    long long get(long long x)
    {
        if(x < 0) return 0;

        s = to_string(x);

        memset(vis,0,sizeof(vis));

        return solve(0,1,0,-1,-1).wave;
    }

    long long totalWaviness(long long num1, long long num2) {
        return get(num2) - get(num1-1);
    }
};