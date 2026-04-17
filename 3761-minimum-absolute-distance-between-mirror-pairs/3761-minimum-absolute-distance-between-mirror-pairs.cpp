class Solution {
public:
    int reverse(int num){
        int rev=0;
        while(num>0){
            rev = rev*10 + num%10;
            num/=10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int>mp;
        int ans=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(mp.count(nums[i])){
                ans = min(ans, i-mp[nums[i]]);
            }
            mp[reverse(nums[i])] =i;
        }
        return ans == INT_MAX ? -1: ans;
    }
};