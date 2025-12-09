class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int>totalFreq;
        for(int num: nums){
            totalFreq[num]++;
        }
        long long ans=0;
        long long mod=1e9+7;
        unordered_map<int, int>prefix;
        for(int i: nums){
            int total = totalFreq[2*i];
            int left = prefix[2*i];
            int right = i==0? (total-left-1): (total-left);
            prefix[i]++;
            ans = (ans + (left*1LL*right))%mod;
        }
        return ans;
    }
};