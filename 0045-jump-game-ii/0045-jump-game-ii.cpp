class Solution {
public:
    int jump(vector<int>& nums) {
     int ind=0, ans=0;
        for(int i=1; i<nums.size(); i++){
            nums[i]= max(nums[i]+i, nums[i-1]);
        }
        while(ind<nums.size()-1){
            ans++;
            ind= nums[ind];
        }
        return ans;
    }
};