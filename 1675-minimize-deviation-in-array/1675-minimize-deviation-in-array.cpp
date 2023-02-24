class Solution {
public:
    int minimumDeviation(vector<int>& nums){
       int diff = INT_MAX;
        int mn = INT_MAX;
        priority_queue<int>maxHeap;
        for(auto i:nums){
            if(i%2!=0)
                i*=2;
            mn = min(mn, i);
            maxHeap.push(i);
        }
        
        while(maxHeap.top()%2==0){
            int mx = maxHeap.top();
            maxHeap.pop();
            diff = min(diff, mx-mn);
            mn  = min(mn, mx/2);
            maxHeap.push(mx/2);
        }
        
        int ans = min(diff, maxHeap.top() - mn);
        return ans;
    }
};