class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int, int>mp;
        int ans=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0){
                mp[nums[i]]++;
            }
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0 && mp.find((-1*nums[i]))!=mp.end()){
                ans= max(ans, nums[i]);
            }
        }
        return ans;
    }
};