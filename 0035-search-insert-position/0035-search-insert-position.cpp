class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
//         bool valueInserted = false;
//         if(nums.size()==0){
//             return 0;
//         }
//         int ans;
//         int s=0, e =nums.size()-1;
//         while(s<=e){
//             int mid =s +(e-s)/2;
//             if(nums[mid]==target){
//                 valueInserted=true;
//                     return mid;
//             }
//            else if(nums[mid]>target){
//                 e = mid-1;
//             }
//             else{
//                 s= mid+1;
//             }
//         }
        
//         // for(int i=0; i<nums.size(); i++){
//         //     if(nums[i]>=target){
//         //         valueInserted =true;
//         //       return i;
//         //     }
//         // }
        
//         if(!valueInserted){
//         ans=  s;
//         }
//         return ans;
        
        // ***********************************************************
        // way-2>
        int n= nums.size();
        int s=0, e= n-1;
        while(s<=e){
            int mid= s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                e= mid-1;
            }
            else{
                s= mid+1;
            }
        }
        
        return s;
        
    }
};