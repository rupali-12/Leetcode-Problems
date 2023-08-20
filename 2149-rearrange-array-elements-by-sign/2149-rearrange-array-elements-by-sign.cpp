class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // int countPos=0, countNeg=0;
        int n= nums.size();
        deque<int>dq;
        // int curr;
        for(int i=n-1; i>=0; i--){
            if(nums[i]<0){
                dq.push_front(nums[i]);
            }
            else{
                dq.push_back(nums[i]);
            }
        }
        int i=0;
        while(!dq.empty()){
            int num1= dq.back();
            int num2= dq.front();
            dq.pop_back();
            dq.pop_front();
            nums[i++]= num1;
            nums[i++]=num2;
        }
        return nums;
    }
};