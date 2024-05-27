class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        int ans=-1;
        for(int x=0; x<=n; x++){
            // pointer t first element >= x
            int idx = lower_bound(begin(nums), end(nums), x) - begin(nums);
            int numGreaterThanX = n-idx; 
            if(numGreaterThanX == x){
                ans= x;
            }
        }
        return ans;
    }
};