class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long totalSum=0;
        for(auto num: nums){
            totalSum+= num;
        }
        int n= nums.size();
        vector<int>delta(n);
        for(int i=0; i<n; i++){
            int Xor = nums[i]^k;
            delta[i] = Xor -nums[i];
        }
        
        sort(delta.begin(), delta.end(), greater<int>());
        int i=0, count=n/2;
        while(count--){
            int temp = delta[i]+delta[i+1];
            i+=2;
            if(temp>0){
                totalSum+= temp;
            }
        }
        return totalSum;
    }
};