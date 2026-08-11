class Solution {
public:
    bool isPresent(vector<int>&nums, int element){
        for(auto num: nums){
            if(num==element) return true;
        }
        return false;
    }
    int missingInteger(vector<int>& nums) {
        int n= nums.size();
        int prefixSum=nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1]+1){
                prefixSum+= nums[i];
            }
            else{
                break;
            }
        }

        int missingnum=prefixSum;
        while(isPresent(nums, missingnum)){
            missingnum++;
        }
        return missingnum;
    }
};