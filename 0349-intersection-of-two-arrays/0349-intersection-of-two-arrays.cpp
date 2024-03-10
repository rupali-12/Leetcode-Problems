class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int>mp;
        for(auto a: nums1){
            mp[a]++;
        }
            
        // // Way-1:    // less faster(25+)
        // vector<int>ans;
        // for(auto num: nums2){
        //     if(mp.find(num)!=mp.end()){
        //         ans.push_back(num);
        //         mp.erase(num);
        //     }
        // }
        // return ans;
        
        // Way-2:    // more faster(85+)
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