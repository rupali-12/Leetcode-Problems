class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        unordered_set<int>st;
        int mn = INT_MAX, mx = INT_MIN;
        for(int i=0; i<nums.size(); i++){
           st.insert(nums[i]);
           mn = min(mn, nums[i]);
           mx = max(mx, nums[i]);
        }
       for(int i=mn; i<=mx; i++){
         if(st.find(i)==st.end()){
            ans.push_back(i);
         }
       }
      return ans;
    }
};
