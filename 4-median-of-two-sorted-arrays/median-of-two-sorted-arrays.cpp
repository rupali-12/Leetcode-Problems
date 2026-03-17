class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans =0;
        int m = nums1.size(), n = nums2.size();
        vector<int>temp(m+n);
        int i=0, j=0, k=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                temp[k]=nums1[i];
                i++; k++;
            }
            else{
                temp[k]=nums2[j];
                j++; k++;
            }
        }

        while(i<m){
            temp[k]=nums1[i];
            i++; k++;
        }

        while(j<n){
            temp[k]=nums2[j];
            j++; k++;
        }

        // odd
        if(temp.size()%2==1){
            ans= temp[temp.size()/2];
        }
        else{
            ans=(temp[temp.size()/2-1] + temp[temp.size()/2])/2.0;
        }
        return ans;
    }
};