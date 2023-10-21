class Solution {
public:
    void solve(vector<int>& candid, int index,vector<vector<int>>&ans, vector<int>&output, 
              int sum, int target){
        if(sum>target) return;
        if(sum==target &&  index<= candid.size()){
            ans.push_back(output);
            return;
        }
        if(index== candid.size()) return;
        
        // case of inclusion 
        output.push_back(candid[index]);
        solve(candid, index, ans, output, sum+candid[index], target);
        output.pop_back();
        
        // case of exclusion 
        solve(candid, index+1, ans, output, sum, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candid, int target) {
         vector<vector<int>>ans;
        vector<int>output;
        int sum=0;
        solve(candid, 0, ans, output, sum, target);
        return ans;
    }
};