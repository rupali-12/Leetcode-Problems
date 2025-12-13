class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        // idx1 = blue_gola_index, idx2 = index which is just greater than blue_gola_index 
        int idx1=-1, idx2=-1;
        
        // find idx1 --> index where nums[i]>nums[i-1]
        for(int i=n-1; i>0; i--){
           if(nums[i]>nums[i-1]){
            idx1=i-1;
            break;
           }
        }

    //    find idx2 only when there is one idx1 exist 
    // idx2-> index where value is just greater than value at index idx1 
        if(idx1!=-1){
            for(int i=n-1; i>idx1; i--){   // idx1+1 se check krna h just greater element
                if(nums[i]>nums[idx1]){
                    idx2= i;
                    break;
                }
            }
            swap(nums[idx1], nums[idx2]);
        }

        reverse(nums.begin() + idx1+1, nums.end());
    }
};