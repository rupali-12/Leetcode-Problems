class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        for(int i=0; i < nums1.size(); i++){
           int l = 0, r = nums2.size()-1;
           while(l<=r){
            int mid= l + (r-l)/2;
            if(nums1[i] <= nums2[mid]){
               ans= max(ans, mid-i);
               l =mid+1;
            } 
            else{
                r = mid-1;
            }
           }
        }
        return ans;
    }
};