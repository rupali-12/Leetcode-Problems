class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int, int>mp;   // currSum->count
        mp[0]=1;
        int currSum=0;
        long long validLeftPoints=0;
        long long res=0;
        for(int j=0; j<nums.size(); j++){
            if(nums[j]==target){
            validLeftPoints+= mp[currSum];
            currSum+=1;
            }
            else{
            currSum-=1;
            validLeftPoints-= mp[currSum];
            }
            mp[currSum]+=1;
            res+= validLeftPoints;
        }
        return res;
    }
};

