class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int>st(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(st.find(original)!=st.end()){
                original*=2;
            }
        }
        return original;
    }
};