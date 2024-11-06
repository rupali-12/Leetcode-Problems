class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n= nums.size();
        bool swapped= true;
        
        for(int i=0; i<n; i++){
            swapped= false;
            
            for(int j=0; j<n-i-1; j++){
                if(nums[j]<nums[j+1]) continue;
                else{
                    // swap is required 
                    if(__builtin_popcount(nums[j])==__builtin_popcount(nums[j+1])){
                        swap(nums[j], nums[j+1]);
                        swapped= true;
                    }
                    else{
                        // array cannot sort 
                        return false;
                    }
                }
            }
              
            if(swapped==false){   // no swap done in this pass
                break;
            }
        }
        
        return true;
    }
};