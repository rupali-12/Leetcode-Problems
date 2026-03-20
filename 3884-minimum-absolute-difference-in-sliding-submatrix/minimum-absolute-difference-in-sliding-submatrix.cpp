class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m =grid.size();
        int n =grid[0].size();
        vector<vector<int>>ans(m-k+1, vector<int>(n-k+1, 0));

        for(int i=0; i<=m-k; i++){
            for(int j=0; j<=n-k; j++){
                set<int>val;
                for(int r = i; r< i+k; r++){   
                  for(int c=j; c<j+k; c++){
                    val.insert(grid[r][c]);
                  }
                }

            int minDiff = INT_MAX;
            auto prev = val.begin();
            auto curr = next(prev);
            if(val.size()<=1){
                ans[i][j]=0;
                continue;
            }
            while(curr!= val.end()){
                minDiff = min(minDiff, abs(*curr - *prev));
                prev= curr;
                curr++;
              }
              ans[i][j] = minDiff;
            }
        }
        return ans;
    }
};