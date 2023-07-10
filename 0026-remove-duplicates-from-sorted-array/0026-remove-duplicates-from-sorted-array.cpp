class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int temp=0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]!= nums[i+1]){
                nums[temp++]= nums[i];
            }
        }
        nums[temp++]= nums[nums.size()-1];
        return temp;
    }
};