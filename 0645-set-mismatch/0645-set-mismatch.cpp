class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
//         // Approach-1 : Using set 
//         int missingnum, repeatednum;
//         int calculatedSum=0, arraySum=0;
//         set<int>s;
//         int n=nums.size();
    
//         int expectedSum= (n*(n+1))/2;
//         for(int i=0; i<nums.size(); i++){
//             n= max(nums[i], n);
//             s.insert(nums[i]);
//             arraySum+= nums[i];
//         }
        
//         for(auto a: s){
//             calculatedSum += a;
//         }
//         missingnum = expectedSum - calculatedSum;
//         repeatednum = arraySum - calculatedSum; 
      
//         return {repeatednum, missingnum};
        
        // ****************************************************************
        
        // Approach-2: Inplace 
         int missingnum, repeatednum;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[abs(nums[i])-1]<0){
                repeatednum = abs(nums[i]);
            }
            else{
                nums[abs(nums[i])-1]*=-1;
            }
        }
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0) missingnum= i+1;
        }
         return {repeatednum, missingnum};
    }
};