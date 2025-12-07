class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        deque<int>dq;

        // process first window 
        for(int i=0; i<k; i++){
            while(!dq.empty() && nums[i]>dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());

        // process remaining window 
        for(int i=k; i<n; i++){
            // if left most element of previous window always be the outgoing element if it is the max element then remove from deque also
            if(dq.front() == nums[i-k]){
                dq.pop_front();
            }

            while(!dq.empty() && nums[i]>dq.back()){
                dq.pop_back();
            }

            dq.push_back(nums[i]);
            ans.push_back(dq.front());
        }
        return ans;
    }
};