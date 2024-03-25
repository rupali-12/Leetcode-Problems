class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n= nums.size();
        vector<int>ans;
       for(int i=0; i<n; i++){
           int ind= (abs(nums[i])-1);   // index of abs(nums)
           if(nums[ind]<0){
               ans.push_back(abs(nums[i]));
           }
           else{
               nums[ind]= -nums[ind];
           }
        }
        return ans;
    }
};