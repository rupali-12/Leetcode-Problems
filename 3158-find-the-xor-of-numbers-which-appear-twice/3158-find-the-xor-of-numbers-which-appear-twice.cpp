class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        // Approach-1: using map
        unordered_map<int, int>mp;
        for(auto a: nums){
            mp[a]++;
        }
        
        int xorAns=0;
        for(auto m: mp){
            if(m.second==2){
                xorAns^= m.first;
            }
        }
        return xorAns;
    }
};