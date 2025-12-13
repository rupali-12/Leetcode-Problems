class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        int temp=0;
        for(int i=0; i<n-1; i++){
            if(nums[i]!=nums[i+1]){
               nums[temp++] = nums[i];
            }
        }
        nums[temp++] = nums[n-1];
        return temp;
    }
};