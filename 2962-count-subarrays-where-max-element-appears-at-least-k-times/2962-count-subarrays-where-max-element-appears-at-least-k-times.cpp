class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int count_of_max=0, max_element;
        int n= nums.size();
        
        // find max element
        for(int i=0; i<n; i++){
            max_element = max(max_element, nums[i]);
        }
        
        // find count of max element 
        for(int i=0; i<n; i++){
            if(nums[i]==max_element) count_of_max++;
        }
        
        int i=0, j=0;
        long long ans=0;
        while(j<n){
            if(nums[j]==max_element){
                k--;
            }
            
           while(k==0){
               ans+= (n-j);
               if(nums[i]==max_element){
                   k++;
               }
               i++;
           }
            
            
            j++;
        }
        return ans;
    }
};