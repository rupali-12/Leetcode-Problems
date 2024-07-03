class Solution {
public:
    int minDiff(vector<int>&nums, int n){
        return min({nums[n-1] - nums[3], 
                    nums[n-2] - nums[2], 
                    nums[n-3] - nums[1], 
                    nums[n-4] - nums[0]});
    }
    int minDifference(vector<int>& nums) {
        int n= nums.size();
        
        // // Approach 1  Brute force 
        if(n<=4) return 0;
        // sort(nums.begin(), nums.end());
        // return minDiff(nums, n);
        
        
        // Approach -2: Using Heap
        priority_queue<int>mxHeap;
        priority_queue<int, vector<int>, greater<int>>mnHeap;
        
        // insert 4 max and min elements 
        for(auto num: nums){
            mxHeap.push(num);
            mnHeap.push(num);
            
            if(mxHeap.size()>4) mxHeap.pop();
            if(mnHeap.size()>4) mnHeap.pop();
        }
        
        
        
        int l= 3, r= n-4;   // (n-1)-3
        while(!mxHeap.empty()){
            nums[l--] = mxHeap.top();
            mxHeap.pop();
            
            nums[r++] = mnHeap.top();
            mnHeap.pop();
        }
        
        return minDiff(nums, n);
    }
};