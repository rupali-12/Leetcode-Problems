class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max1= 0, curr1=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1) curr1++;
            else{
                max1 =max(max1, curr1);
                curr1=0;
            }
            // handle end case like [1,1,0,1,1,1]
            if(i==nums.size()-1){
                max1= max(max1, curr1);
            }
        }
        return max1;
    }
};