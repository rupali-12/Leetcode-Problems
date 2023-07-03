class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Approach-1 using map
        // map<int, int>mp;
        // for(auto a: nums){
        //     mp[a]++;
        // }
        // for(auto a: mp){
        //     if(a.second>1){
        //         return true;
        //     }
        // }
        // return false;
        
        // Approach-2> using sorting
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
    }
};