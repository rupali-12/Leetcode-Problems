class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n= height.size();
        vector<int>nextLarger(n, 0);
        vector<int>prevLarger(n, 0);

        // first calculate prevLarger 
        prevLarger[0] = height[0];
        int i=1;
        while(i<n){
          prevLarger[i] = max(prevLarger[i-1], height[i]);
          i++;
        }

        // first calculate nextLarger 
        nextLarger[n-1]=height[n-1];
        i=n-2;
        while(i>=0){
            nextLarger[i] = max(nextLarger[i+1], height[i]);
            i--;
        }

        for(int i=0; i<n; i++){
            int mnheight= min(prevLarger[i], nextLarger[i]);
            ans+= mnheight - height[i];  // minus height of bar, as to calculate the actual portion which is trapped at a particular place
        }
        return ans;
    }
};