class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int mxSum= INT_MIN;
        if(k>nums.size()) return 0;
        int cnt=0, sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+= nums[i];
            cnt++;
            // if(sum<0){
            //     sum=0;
            //     cnt=0;
            // }
            if(cnt==k){
                mxSum= max(mxSum, sum);
            }
            else if(cnt>k){
                sum-= nums[i-k];
                mxSum= max(mxSum, sum);
            }
        }
        double ans= (double)(mxSum)/k;
        return ans;
    }
};