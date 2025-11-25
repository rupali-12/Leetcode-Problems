class Solution {
public:
//   short: if ith idx  value is positive means number i+1 is missing as we are marking i-1th idx as negative if nums[i] is posite and i-1 is valid
// example 
// index0 → negative → 1 present
// index1 → negative → 2 present
// index4 → positive → 5 is missing

    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();

        // mark all neg and 0 as n+1
        for(int i=0; i<n; i++){
            if(nums[i]<=0){
                nums[i] = n+1;
            }
        }

        // mark nums[i] as neg if index possible
        for(int i=0; i<n; i++){
            int idx = abs(nums[i])-1;
            // if idx is possible then make it negative 
            if(idx<n && nums[idx]>0){  // make sure nums[idx] should be positive to make it negative if it is neg  already then it will become positive
            nums[idx]*= -1;
            }
        }

        // check now, if value at any idx is positive it means it value+1 is not present 
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        
        return n+1;
    }
};