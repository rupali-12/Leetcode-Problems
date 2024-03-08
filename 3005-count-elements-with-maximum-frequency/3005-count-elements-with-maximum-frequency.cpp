class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int>mp;
        int mxFreq=0;
        for(auto a: nums){
            mp[a]++;
            mxFreq= max(mxFreq, mp[a]);
        }
        
        int count=0;
        for(auto m: mp){
           if(m.second==mxFreq){
               count+= m.second;
           }
        }
        return count;
    }
};