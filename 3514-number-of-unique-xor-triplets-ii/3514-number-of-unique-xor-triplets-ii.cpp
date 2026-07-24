class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        //  store all pair XOR
        unordered_set<int>st;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                st.insert(nums[i]^nums[j]);
            }
        }

        unordered_set<int>st2;
        // find triplet Xor's
        for(auto x: st){
            for(int &val: nums){
                st2.insert(x^val);
            }
        }
        return st2.size();
    }
};