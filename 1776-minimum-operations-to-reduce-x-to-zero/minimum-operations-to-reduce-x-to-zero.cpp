class Solution {
public:
typedef long long ll;
    int minOperations(vector<int>& nums, int x) {
        ll totalSum =0, n=nums.size();
        for(int i=0; i<n; i++) totalSum += nums[i];
        ll target = totalSum - x;
        if(target==0) return n;   // remove everything

        int i=0, maxLen =-1, j=0;
        ll sum=0;
        while(j<n){
           sum += nums[j];

           while(i<=j && sum > target){
            sum-= nums[i];
            i++;
           }

           if(sum == target){
            maxLen = max(maxLen, j-i+1);
           }
           j++;
        }

        if(maxLen ==-1) return -1;
        return n-maxLen;
    }
};