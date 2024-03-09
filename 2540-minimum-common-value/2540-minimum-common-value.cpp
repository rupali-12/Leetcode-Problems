class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int ans=-1;
        map<int, int>mp;
        for(auto a: nums1){
            mp[a]++;
        }
        
        while(i<nums2.size()){
            if(mp[nums2[i]]>0){
                ans= nums2[i];
                break;
            }
            i++;
        }
        return ans;
    }
};