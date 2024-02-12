class Solution {
public:
    int majorityElement(vector<int>& nums) {
    //     map<int, int>mp;
    //   for(int i=0; i<nums.size(); i++){
    //       mp[nums[i]]++;
    //         if(mp[nums[i]] > nums.size()/2){
    //             return nums[i];
    //         }
    //   }
    //     return -1;

    // Approach 2-> sort 
    int n= nums.size();
    sort(nums.begin(), nums.end());
    return nums[n/2];
    }
};