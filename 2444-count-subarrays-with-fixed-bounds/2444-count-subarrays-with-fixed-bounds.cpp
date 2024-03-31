class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int minPosition= -1, maxPosition=-1, culIndex=-1;
        int i=0, j=0, n= nums.size();
        
        for(int i=0; i<n; i++){
           if(nums[i]<minK || nums[i]>maxK) culIndex=i;  
            
            if(nums[i]==minK)
                minPosition=i;
            
            if(nums[i]==maxK)
                maxPosition=i;
            
           int smaller= min(minPosition, maxPosition); 
            
            int temp= smaller - culIndex;
            
            ans+= (temp<0)?0: temp;
        }
        
        return ans;
    }
};