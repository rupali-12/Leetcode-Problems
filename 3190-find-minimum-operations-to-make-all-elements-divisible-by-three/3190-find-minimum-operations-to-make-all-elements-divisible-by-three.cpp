class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count=0;
        for(int i=0; i<nums.size(); i++){
            int rem = nums[i]%3;
            int upper = nums[i] + (3 - rem);
            int lower = nums[i] - rem;
            count+= min((upper-nums[i]), (nums[i]-lower));
        }
        return count;
    }
};