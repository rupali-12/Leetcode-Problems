class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>prevLargest(n), nextLargest(n);
       
        prevLargest[0]= height[0];
         int i=1;
        while(i<n){
            prevLargest[i] = max(prevLargest[i-1], height[i]);
            i++;
        }
        
        nextLargest[n-1]= height[n-1];
         i= n-2;
        while(i>=0){
            nextLargest[i] = max(nextLargest[i+1], height[i]);
            i--;
        }
        
        int ans=0;
        for(i=0; i<n; i++){
            int mn= min(nextLargest[i], prevLargest[i]);
            ans+= (mn-height[i]);
        }
        return ans;
    }
};