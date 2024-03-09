class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
//         // Approach-1: With space 
//         int i=0;
//         int ans=-1;
//         map<int, int>mp;
//         for(auto a: nums1){
//             mp[a]++;
//         }
        
//         while(i<nums2.size()){
//             if(mp[nums2[i]]>0){
//                 ans= nums2[i];
//                 break;
//             }
//             i++;
//         }
//         return ans;
        
        // Approach-2: without extra space
        int n1= nums1.size(), n2= nums2.size();
        if(n1>n2){
            swap(nums1, nums2);
            swap(n1, n2);
        }
        
        int prev=0;
        for(int i=0; i<n1; i++){
            int x=nums1[i];
            
            // find lower bound of x 
            int j= lower_bound(nums2.begin()+prev, nums2.end(), x)-nums2.begin();
            if(j==n2) return -1;
            else if(x==nums2[j]) return x;
            else prev= j;
        }
        return -1;
    }
};




