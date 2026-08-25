class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st;
        for (auto n: nums){
            st.insert(n);
        }
        int multiple=k;
        while(st.count(multiple)){
            multiple+=k;
        }
        return multiple;
    }
};