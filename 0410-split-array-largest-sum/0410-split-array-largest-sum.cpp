class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n= nums.size();
        int mx=INT_MIN, sum=0;
        
        for(int i=0; i<n; i++){
            sum+= nums[i];
            if(nums[i]>mx){
                mx= nums[i];
            }
        }
        
        int s=mx, e= sum, ans=-1;
        while(s<=e){
            int mid= s+(e-s)/2;
            
     int currSum=0, numArrays=1;
            for(int i=0; i<n; i++){
               currSum+= nums[i];
                if(currSum>mid){
                    numArrays++;
                    currSum= nums[i];
                }
            }
            
            if(numArrays<=k){
                ans= mid;
                e= mid-1;
            }
            else{
                s= mid+1;
            }
        }
        return ans;
    }
};