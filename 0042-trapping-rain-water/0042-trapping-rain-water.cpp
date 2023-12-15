class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        vector<int>left(n), right(n);
        left[0]= height[0];
        int i=1;
        while(i<n){
            left[i]= max(left[i-1], height[i]);
            i++;
        }
        
        i= n-2;
        right[n-1]= height[n-1];
        while(i>=0){
            right[i]=max(right[i+1], height[i]);
            i--;
        }
        
        int ans=0;
        for(int k=0; k<n; k++){
            int mn = min(left[k], right[k]);
            ans+= mn- height[k];
        }
        return ans;
    }
};