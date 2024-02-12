class Solution {
public:
    void solve(vector<int>nums, int index, vector<vector<int>>&ans){
        if(index==nums.size()){
            ans.push_back(nums);
        }
        for(int i=index; i<nums.size(); i++){
            swap(nums[i], nums[index]);
            solve(nums, index+1, ans);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        int index=0;
            solve(nums, index, ans);
        
        // To find unique 
        set<vector<int>>s;
        for(auto v: ans){
            s.insert(v);
        }
        ans.clear();
        for(auto a: s){
            ans.push_back(a);
        }
        return ans;
    }
};