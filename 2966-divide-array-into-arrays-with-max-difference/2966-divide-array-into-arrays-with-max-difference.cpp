class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n= nums.size();
        vector<vector<int>>ans(n/3, vector<int>(3));
        
         // sort nums 
        sort(nums.begin(), nums.end());
       int index=0;
        
        for(int i=0; i<nums.size(); i+=3){
           if(i+2<n && (nums[i+2]-nums[i])<=k){
               ans[index] = {nums[i], nums[i+1], nums[i+2]};
               index++;
           }
            else{
                ans.clear();
                return ans;
            }
        }
        return ans;
    }
};