class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixGcd(n);
        int mx = nums[0];
        for(int i=0; i<n; i++){
            mx = max(nums[i], mx);
            prefixGcd[i] = __gcd(nums[i], mx);
        }

        sort(prefixGcd.begin(), prefixGcd.end());
        int i=0, j=n-1;
        long long ans=0;
        while(i<j){
          ans+= __gcd(prefixGcd[i], prefixGcd[j]);
          i++;
          j--;
        }
        return ans;
    }
};