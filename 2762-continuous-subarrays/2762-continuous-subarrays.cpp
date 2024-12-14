class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        int i=0, j=0;
        deque<int>maxDeque, minDeque;   // store indices 
        while(j<nums.size()){
           // maintain maxDeque for max element 
            while(!maxDeque.empty() && nums[maxDeque.back()]<nums[j]){
                maxDeque.pop_back();
            }
            maxDeque.push_back(j);
            
             // maintain minDeque for min element 
            while(!minDeque.empty() && nums[minDeque.back()]>nums[j]){
                minDeque.pop_back();
            }
            minDeque.push_back(j);
    
            // maintain i 
            while((nums[maxDeque.front()] - nums[minDeque.front()])>2){
                if(maxDeque.front()==i){   // is its i then pop it as we shift i to i+1
                    maxDeque.pop_front();
                }
                
                if(minDeque.front()==i){
                    minDeque.pop_front();
                }
                i++;
            }
            
            ans+= static_cast<long long>(j-i+1);
            j++;
        }
        return ans;
    }
};