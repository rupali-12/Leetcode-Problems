class Solution {
public:
    int n;
    vector<vector<int>>ans;
    void solve(vector<int>&nums, int index){
        if(index == n){
            ans.push_back(nums);
            return;
        }

       for(int i=index; i<n; i++){
        swap(nums[i], nums[index]);
        solve(nums, index+1);
        swap(nums[i], nums[index]);
       }
    }
    vector<vector<int>> permute(vector<int>& nums) {
      n = nums.size();
      int index = 0;
      solve(nums, index);
      return ans;
    }
};