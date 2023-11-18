class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int left=0, right=0;
        long sum=0; 
        int ans=1;
        sort(nums.begin(), nums.end());
        while(right<nums.size()){
            sum+= nums[right++];
            if((sum+k) < ((long)nums[right-1]*(right-left))){
                sum-= nums[left];
                left++;
            }
            ans= max(ans, right-left);
        }
        return ans;
    }
};