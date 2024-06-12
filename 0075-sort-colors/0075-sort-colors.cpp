class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num0=0, num1=0, num2=0;
        for(auto num: nums){
            if(num==0) num0++;
            else if(num==1) num1++;
            else num2++;
        }
        
        int i=0;
        while(num0--) nums[i++]=0;
        while(num1--) nums[i++]=1;
        while(num2--) nums[i++]=2;
        
        return;
    }
};