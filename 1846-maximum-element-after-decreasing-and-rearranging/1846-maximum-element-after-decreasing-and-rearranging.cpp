class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int ans=1;
        sort(arr.begin(), arr.end());
        
        arr[0]=1;
        for(int i=1; i<arr.size(); i++){
            if(abs(arr[i]-arr[i-1])<=1){
                continue;
            }
            else{
                arr[i]= arr[i-1]+1;
            }
        }
        
        for(int i=0; i<arr.size(); i++){
            ans= max(ans, arr[i]);
        }
        return ans;
    }
};