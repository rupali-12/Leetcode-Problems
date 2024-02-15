class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ans=-1;
        int n= nums.size();
        sort(nums.begin(), nums.end());
        vector<long long>prefix(n);
        prefix[0]=nums[0];
        for(int i=1; i<n; i++){
            prefix[i] = nums[i] + prefix[i-1];
        }
        
        for(int i=n-1; i>=2; i--){
            if(nums[i]<prefix[i-1]){
                ans= prefix[i];
                break;
            }
        }
        return ans;
    }
};