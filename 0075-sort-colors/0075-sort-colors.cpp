class Solution {
public:
    void sortColors(vector<int>& nums) {
        // for(int i=0; i<nums.size()-1; i++){
        //    for(int j=i+1; j<nums.size(); j++){
        //        if(nums[i]>nums[j]){
        //            int temp =nums[i];
        //            nums[i]= nums[j];
        //            nums[j]=temp;
        //        }
        //    }
        // }
        
        // Approach-2 ->Binary Search 
        int i=0, mid=0, j=nums.size()-1;
        while(mid<=j){
            if(nums[mid]==0){
                swap(nums[mid], nums[i]);
                i++; mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid], nums[j]);
                j--;
            }
        }
        return;
    }
};