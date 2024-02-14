class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        deque<int>dq;
        for(int i=n-1; i>=0; i--){
            if(nums[i]>0){
                dq.push_front(nums[i]);
            }
            else{
                dq.push_back(nums[i]);
            }
        }
        
        int i=0;
        while(!dq.empty()){
            int num1= dq.front();
            int num2= dq.back();
            dq.pop_front();
            dq.pop_back();
            nums[i++]= num1;
            nums[i++]= num2;
        }
        return nums;
    }
};