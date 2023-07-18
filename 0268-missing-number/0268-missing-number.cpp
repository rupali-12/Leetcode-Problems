class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int calSum=0;
        int n=nums.size();
        for(int i=0; i<nums.size(); i++){
   calSum+=nums[i];
        }
        int actSum = (n*(n+1))/2;
        return actSum-calSum;
    }
};