class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n= nums.size();
        int sum = 0;
        int minElement=nums[0];
        for(auto num: nums){
            sum+= num;
            minElement= min(num, minElement);
        }
        int ans = sum - (n*minElement);
        return ans;
    }
};