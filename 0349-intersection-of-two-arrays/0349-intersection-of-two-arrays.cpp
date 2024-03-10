class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int>mp;
        for(auto a: nums1){
            mp[a]++;
        }
        
        set<int>s;
        for(auto a: nums2){
            if(mp[a]>0){
                s.insert(a);
            }
        }
        vector<int>ans(s.begin(),s.end());
        return ans;
    }
};