class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            int a =nums[i];
            int t=-a;
            int start=i+1, end=nums.size()-1;
            while(start<end){
                if(nums[start]+nums[end]==t){
                    ans.push_back({nums[i], nums[start], nums[end]});
                    while(start<end && nums[start]==nums[start+1]){
                        start++;
                    }
                    while(start<end && nums[end]==nums[end-1]){
                        end--;
                    }
                    start++; end--;
                }
                else if(nums[start]+nums[end]<t){
                    start++;
                }
                else{
                    end--;
                }
            }
            while((i+1)<nums.size() && (nums[i+1]==nums[i])){
                i++;
            }            
        }
        return ans;
    }
};