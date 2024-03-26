class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n= nums.size();
        
        // make all neg and 0 as n+1
        for(int i=0; i<n; i++){
            if(nums[i]<=0){
                nums[i]= n+1;
            }
        }
        
        // mark nums[i] as neg if index possible 
        for(int i=0; i<n; i++){
            int index= abs(nums[i])-1;
            if(index<n && nums[index]>0){  /// nums[index]>0 as it should not be already neg bcoz then it will become positive
                 nums[index]*= -1;
            }
        }
        
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        
        return n+1;
    }
};