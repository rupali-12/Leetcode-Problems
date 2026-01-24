class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int sum= INT_MIN;
        sort(nums.begin(), nums.end());
        int i=0, j= nums.size()-1;
        while(i<j){
            sum = max(nums[i]+nums[j], sum);
            i++;
            j--;
        }
        return sum;
    } 
};