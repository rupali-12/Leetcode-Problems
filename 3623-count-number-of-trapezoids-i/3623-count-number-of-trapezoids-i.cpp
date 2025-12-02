class Solution {
public:
    int MOD = 1e9 +7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int>mp;
        int ans=0, sum=0;
        for(auto p: points){
            mp[p[1]]++;
        }

        for(auto m: mp){
            long long count =(1LL* m.second* (m.second-1)/2)%MOD;
            ans = (ans + (sum*count))%MOD;
            sum = sum + count;
        }
        return ans;
    }
};