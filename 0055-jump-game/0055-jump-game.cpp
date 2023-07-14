class Solution {
public:
    bool canJump(vector<int>& nums) {
         if(nums.size() ==1){
                return true;
            }
            if(nums[0]==0 && nums.size() >1){
                return false;
            }
        
        int index= nums.size()-1;
        int i=index;
        while(i>=0){
            if(nums[i]+i>= index){
                index= i;
            }
            i--;
        }
        if(index==0){
            return true;
        }
        return false;
    }
};