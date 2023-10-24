class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(), nums.end());
        int currcount=0, lastSmaller= INT_MIN, longestLen=1;
        for(int i=0; i<nums.size(); i++){
            // case of consecutive 
            if(nums[i]-1 == lastSmaller){
                currcount++;
                lastSmaller= nums[i];
            }
            // case of non consecutive and not equal 
            else if(lastSmaller!=nums[i]){
                currcount=1;
                lastSmaller= nums[i];
            }
            longestLen = max(longestLen, currcount);
        }
       return longestLen;
    }
};