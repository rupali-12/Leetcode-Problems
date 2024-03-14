class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count=0, n= nums.size(), prefixsum=0;
unordered_map<int, int>mp;
mp[0]=1;        
        for(int i=0; i<n; i++){
          prefixsum+= nums[i];
            count+= mp[prefixsum-goal];
            mp[prefixsum]++;
        }
        return count;
    }
};