class Solution {
public:
 
    int singleNonDuplicate(vector<int>& nums) {
        // int ans;
         int s =0, e= nums.size()-1;
          int mid =s+(e-s)/2;
 while(s<e){
             
        //      if(s==e){
        //     return nums[s];
        // }
        if(mid%2==0){
            if(nums[mid]==nums[mid+1]){
                s =mid+2;
            }
            else{
                e=mid-1;
            }
        }
        else{
              if(nums[mid]==nums[mid+1]){
                e= mid-1;
            }
            else{
                s=mid+1;
            }
        }
    mid =s+(e-s)/2;
        }
        return nums[s];
    }
};