class Solution {
public:
    typedef pair<int, int>P;
    int longestSubarray(vector<int>& nums, int limit) {
        int ans=0;
        int i=0, j=0;
        priority_queue<P>mxHeap;
        priority_queue<P, vector<P>, greater<P>>mnHeap;
        int n= nums.size();
        while(j<n){
            mxHeap.push({nums[j], j});
            mnHeap.push({nums[j], j});
            
            // shrink
            while(mxHeap.top().first - mnHeap.top().first > limit){
                i= min(mnHeap.top().second, mxHeap.top().second) + 1;   // point next to required place
                
                while(mnHeap.top().second <i){
                    mnHeap.pop();
                }
                
                  while(mxHeap.top().second <i){
                    mxHeap.pop();
                }
            }
            ans = max(ans, (j-i+1));
            j++;
        }
        return ans;
    }
};