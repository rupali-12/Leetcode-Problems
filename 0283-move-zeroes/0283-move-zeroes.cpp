class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       // int i=0, j=nums.size();
       // while(i<j){
       //     if(nums[i]==0){
       //         nums.erase(nums.begin()+i);
       //         nums.push_back(0);
       //         j--;
       //     }
       //     else{
       //         i++;
       //     }
       // }
        
        // another Approach>>>>>>
        int i=0;
        for(int j=0; j<nums.size(); j++){
            if(nums[j]!=0){
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};