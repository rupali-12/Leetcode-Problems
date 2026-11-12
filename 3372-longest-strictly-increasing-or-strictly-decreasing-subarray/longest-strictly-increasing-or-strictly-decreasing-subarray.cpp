class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int mxLen =1, up=1, down=1;
        for(int i=1; i<nums.size(); ++i){
            up = nums[i-1]< nums[i] ? up+1: 1;
            down = nums[i-1]> nums[i] ? down+1: 1;
            mxLen = max({mxLen, up, down});
        }
        return mxLen;
    }
};