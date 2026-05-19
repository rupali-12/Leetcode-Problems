class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        // Approach -1 with space
        unordered_set<int>st;
        for(int num: nums1){
            st.insert(num);
        }

        for(int i=0; i<n2; i++){
            if(st.find(nums2[i])!=st.end()){
                return nums2[i];
            }
        }
        return -1;
    }
};