class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n= nums.size();
         if(n==1) return 1;
        int prevDiff=nums[1]-nums[0];
        int  totalElement=0;
        if(prevDiff!=0) totalElement= 2;
        else totalElement = 1;
        
        for(int i=2; i<n; i++){
          int  currDiff= (nums[i]-nums[i-1]);
            if((currDiff>0 && prevDiff<=0) || (currDiff<0 && prevDiff>=0)){
                totalElement++;
             prevDiff= currDiff;
            }
        }
        return totalElement;
    }
};