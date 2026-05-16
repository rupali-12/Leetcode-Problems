class Solution {
public:
    int findMin(vector<int>& nums) {
        int mn= nums[0];
        int n= nums.size();
        for(int i=0; i<n; i++){
            mn= min(mn, nums[i]);
        }
        return mn;
    }
};