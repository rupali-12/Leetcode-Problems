class Solution {
public:
    void solve(vector<int>nums, vector<int>output, int index, vector<vector<int>>&ans){
        if(index>nums.size()-1){
            ans.push_back(output);
            return;
        }
        
        // case of exclusion 
      solve(nums, output, index+1, ans);
        
        // case of inclusion 
        output.push_back(nums[index]);
        solve(nums, output, index+1, ans);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        int index=0;
        solve(nums, output, index, ans);
        return ans;
    }
};