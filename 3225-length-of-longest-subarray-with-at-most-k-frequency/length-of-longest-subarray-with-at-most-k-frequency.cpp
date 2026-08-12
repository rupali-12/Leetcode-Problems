class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int mxLength =0, n = nums.size();
        int i=0, j=0;
        unordered_map<int, int>mp;
        while(j<n){
            mp[nums[j]]++;
           while(mp[nums[j]] > k){
            mp[nums[i]]--;
            i++;
           }
            mxLength = max(mxLength, j-i+1);
            j++;
        }
        return mxLength;
    }
};

// 1 = 2
// 2 = 2
// 3 = 3