class Solution {
public:
    bool isBinarySearch(vector<int>&nums, int num){
        int l=0, r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==num) return true;
            else if(nums[mid]>num) r=mid-1;
            else l=mid+1;
        }
        return false;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();

        // // Approach -1 with space
        // unordered_set<int>st;
        // for(int num: nums1){
        //     st.insert(num);
        // }

        // for(int i=0; i<n2; i++){
        //     if(st.find(nums2[i])!=st.end()){
        //         return nums2[i];
        //     }
        // }
        // return -1;

        // Approach-2: Binary Search
        for(int num: nums1){
            if(isBinarySearch(nums2, num)){
                return num;
            }
        }
        return -1;
    }
};