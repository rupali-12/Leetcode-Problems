class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n =nums.size();
        int mod =1e9+7;
        int i=0;
        while(i<queries.size()){
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];
            for(int j=l; j<=r; j+=k){
               nums[j] = (1LL * nums[j] * v) % mod;
            }
            i++;
        }

        long long ans=0;
        for(int idx=0; idx<n; idx++){
           ans = ans^nums[idx];
        }
      return ans;
    }
};