class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool>ans;
        int sum=0;
       for(int i: nums){
        sum = sum*2;
        sum = (sum+i)%5;
        ans.push_back(sum==0?true: false);
       }
        return ans;
    }
};