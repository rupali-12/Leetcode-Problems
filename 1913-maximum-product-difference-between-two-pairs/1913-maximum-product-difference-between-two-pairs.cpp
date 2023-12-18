class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        // // Approach-1: using Sorting 
        // int n= nums.size();
        // sort(nums.begin(), nums.end());
        // int ans= (nums[n-1]*nums[n-2]) - (nums[0]*nums[1]);
        // return ans;
        
        // Approach-2: using exchange fucntion and without sorting 
        int n= nums.size();
        int biggest=0, secBiggest =0, smallest=INT_MAX, secSmallest= INT_MAX;
        for(int num: nums){
            secBiggest = (num>biggest)?exchange(biggest, num):max(secBiggest, num);
            secSmallest = (num<smallest)?exchange(smallest, num):min(secSmallest, num);
        }
        int ans= biggest*secBiggest - smallest*secSmallest;
        return ans;
    }
};