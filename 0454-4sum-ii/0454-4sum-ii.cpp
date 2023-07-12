class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count=0;
        int n= nums1.size();
        unordered_map<int, int>mp;
        // step-1> store count of each elements of nums4 array 
       for(int i=0; i<nums1.size();i++){
           for(int j=0; j<nums2.size(); j++){
               mp[nums1[i]+nums2[j]]++;
           }
       }
        
        // step-2> process using three loops 
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                    int val= nums3[i]+nums4[j];
                    val= -1*val;
                    if(mp.find(val)!=mp.end()){
                        count+= mp[val];
                    }
                }
        }
        return count;
    }
};