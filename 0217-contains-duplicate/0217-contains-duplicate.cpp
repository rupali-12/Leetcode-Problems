class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>st;
        for(auto n: nums){
            if(st.find(n)!=st.end()){
                return true;
            }
            st.insert(n);
        }
        return false;
    }
};