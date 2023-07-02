class Solution {
public:
   
    int subarraysDivByK(vector<int>& nums, int k) {
       int currSum=0, count=0;
        unordered_map<int, int>mp;
        mp[0]=1;
        for(int i=0; i<nums.size(); i++){
            currSum+=nums[i];
            // int rem= ((currSum%k)+k)%k;
            // Also write like
            int rem= currSum%k;
            if(rem<0) rem+=k;
            if(mp.find(rem)!=mp.end()){
                count+= mp[rem]; 
            }
            mp[rem]++;
        }
        return count;
    }
};