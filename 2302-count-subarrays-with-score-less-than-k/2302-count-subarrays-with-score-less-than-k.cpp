class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0;
        int n= nums.size();
        int i=0, j=0;
        long long sum=0;
        while(j<n){
            int len= j-i+1;
            sum+= nums[j];
            while(i<=j && (sum*len)>=k){
                sum-= nums[i];
                i++;
                len= j-i+1;  // update len after shrinking window
            }
            
            ans+= j-i+1;
            j++;
        }
        return ans;
    }
};