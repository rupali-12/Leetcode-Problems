class Solution {
public:
  typedef long long ll;
   vector<vector<ll>>dp;
    ll solve(int r, int f, vector<int> robots, vector<int> positions){
        if(r >= robots.size()) return 0;
        if(f >= positions.size()) return LLONG_MAX;
        if(dp[r][f]!=-1){
            return dp[r][f];
        }

        ll next = solve(r+1, f+1, robots, positions);
        ll take_curr_factory;
        if(next != LLONG_MAX){   
            take_curr_factory = abs((ll)robots[r] - positions[f]) + next;
        }

        ll skip_curr_factory = solve(r, f+1, robots, positions);

        return dp[r][f] = min(take_curr_factory, skip_curr_factory);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // // Approach: 1 Using DP _Memoization
        // // sort
        // sort(robot.begin(), robot.end());
        // sort(factory.begin(), factory.end());

        // // Expand all factory to avoid limit processing
        // vector<int>positions;
        // for(int i=0; i<factory.size(); i++){
        //     int pos = factory[i][0];
        //     int limit = factory[i][1];

        //     for(int j=0; j<limit; j++){
        //         positions.push_back(pos);
        //     }
        // }

        //  dp = vector<vector<ll>>(robot.size()+1, vector<ll>(positions.size()+1, -1));

        // // recursion
        // return solve(0, 0, robot, positions);

        // Approach -2: Top Bottom 
         sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // Expand all factory to avoid limit processing
        vector<int>positions;
        for(int i=0; i<factory.size(); i++){
            int pos = factory[i][0];
            int limit = factory[i][1];

            for(int j=0; j<limit; j++){
                positions.push_back(pos);
            }
        }
        int n=robot.size();
        int m=positions.size();
        dp = vector<vector<ll>>(n+1, vector<ll>(m+1, LLONG_MAX));
        
        // No robot left
        for(int j=0; j<=m; j++){
            dp[n][j]=0;
        }

        for(int i= n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                ll skip= dp[i][j+1];

                ll take=LLONG_MAX;
                if(dp[i+1][j+1]!=LLONG_MAX){
                    take = abs((ll)robot[i]-positions[j])+dp[i+1][j+1];
                }
                dp[i][j] =min(take, skip);
            }
        }
       return dp[0][0];
    }
};