class Solution {
public:
    void solve(vector<int>nums, vector<vector<int>>&ans,vector<int>output, int index){
         // heare no need to push when index== arr.size() as we need to find seubset of all sizes 
     ans.push_back(output);
        for(int j= index; j<nums.size(); j++){
            if(j>index && nums[j]==nums[j-1]){
                continue;
            }
            output.push_back(nums[j]);
            solve(nums, ans, output, j+1);
            output.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>output;
        int index=0;
        solve(nums, ans, output, index);
        
        return ans;
    }
};