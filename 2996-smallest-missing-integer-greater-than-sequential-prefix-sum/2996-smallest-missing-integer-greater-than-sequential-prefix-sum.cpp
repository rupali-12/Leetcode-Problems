class Solution {
public:
    bool isPresent(vector<int>&nums, int element){
        for(auto x: nums){
            if(x==element){
                return true;
            }
        }
        return false;
    }
    int missingInteger(vector<int>& nums) {
        int prefixsum=nums[0];
        int n= nums.size();
        for(int i=1;i<n; i++){
          if(nums[i]==(nums[i-1]+1)){
              prefixsum+= nums[i];
          }  
            else{
                break;
            }
        }
        
        int missingnum=prefixsum;
        while(isPresent(nums, missingnum)){
            missingnum++;
        }
        return missingnum;
    }
};