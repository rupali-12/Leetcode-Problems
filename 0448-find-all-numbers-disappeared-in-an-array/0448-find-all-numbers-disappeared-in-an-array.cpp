class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n= nums.size();
        map<int, int>mp;
        for(auto num: nums){
            mp[num]++;
        }
        
        vector<int>ans;
        for(int i=1; i<=n; i++){
           if(mp[i]==0){
               ans.push_back(i);
           }
        }
        return ans;
    }
};