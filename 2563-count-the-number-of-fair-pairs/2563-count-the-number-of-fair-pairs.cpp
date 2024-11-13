class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n= nums.size();
        
        sort(nums.begin(), nums.end());
        
        long long ans=0;
        
        for(int i=0; i<n; i++){
            int idx = lower_bound(begin(nums)+i+1, end(nums), (lower-nums[i]))- begin(nums);   // give first index of element which is not less than (lower-nums[i])  || i+1 bcoz of ith index
            
            int x = idx-1-i;   // -1 bcox to find index
            
              idx = upper_bound(begin(nums)+i+1, end(nums), (upper-nums[i])) - begin(nums);   // give first index of element which is greater than (upper-nums[i])  || i+1 bcoz of ith index
            
            int y = idx-1-i;   // -1 bcox to find index
            
            ans+= (y-x);
        }
        return ans;
    }
};