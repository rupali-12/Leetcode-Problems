class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx1, idx2;
        // find idx1 --> which is index where nums[i]<ums[i+1]
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                idx1 = i;
                break;
            }
        }
        if(idx1<0){
            sort(nums.begin(), nums.end());
            return;
        }
         // find idx2 --> which is index wher value is just greater than value at index idx1
       else{
            for(int i=nums.size()-1; i>=0; i--){
            if(nums[i]>nums[idx1]){
                idx2 = i;
                break;
            }
        }
        
        // swap value at idx1 and value at idx2 
        swap(nums[idx1], nums[idx2]);
        
        // sort right part of idx1 
        sort(nums.begin()+idx1+1, nums.end());
       }
    }
};