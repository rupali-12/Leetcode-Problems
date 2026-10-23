class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans =-1;
        for(int i=0; i<n; i++){
          if(i != nums[i]){
            int curr = i & nums[i];
            if(ans==-1) ans = curr;
            else ans &= curr;
          }
        }
        return ans==-1? 0: ans;
    }
};