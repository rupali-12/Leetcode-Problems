class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n= nums.size();
        int ans=0;
        unordered_map<long, int>mp[n]; // array of map 
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                long diff= (long)nums[i]-nums[j];
                auto it = mp[j].find(diff);    // iterator at j for diff= diff
                int count_at_j = it == end(mp[j])? 0: it->second;
                mp[i][diff] += count_at_j +1;
                ans+= count_at_j;
            }
        }
        return ans;
    }
};