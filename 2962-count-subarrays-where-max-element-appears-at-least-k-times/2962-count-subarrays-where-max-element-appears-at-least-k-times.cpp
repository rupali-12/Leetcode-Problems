class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_element;
        int n= nums.size();
        
        // find max element
        for(int i=0; i<n; i++){
            max_element = max(max_element, nums[i]);
        }
        
        
//         // Approach-1: Sliding Window 
//         int i=0, j=0, count=0;
//         long long ans=0;
//         while(j<n){
//             if(nums[j]==max_element){
//                 count++;
//             }
            
//            while(count>=k){
//                ans+= (n-j);
//                if(nums[i]==max_element){
//                    count--;
//                }
//                i++;
//            }
            
            
//             j++;
//         }
//         return ans;
        
        // Approach-2: With Space Complexity
        long long ans=0;
        vector<int>indices;
        for(int i=0; i<n; i++){
            if(nums[i]==max_element){
                indices.push_back(i);
            }
            int size= indices.size();
            if(size>=k){
                int last_i = indices[size-k];
                ans+= last_i +1;
            }
        }
        return ans;
    }
};