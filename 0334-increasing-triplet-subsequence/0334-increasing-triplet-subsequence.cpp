class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first_smaller=INT_MAX, second_smaller = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=first_smaller){
                first_smaller= nums[i];
            }
            else if(nums[i]<=second_smaller){
                second_smaller = nums[i];
            }
            else{
                return true;
            }
        }
        return false;
    }
};