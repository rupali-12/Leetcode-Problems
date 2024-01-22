class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int missingnum, repeatednum;
        int calculatedSum=0, arraySum=0;
        set<int>s;
        int n=nums.size();
    
        int expectedSum= (n*(n+1))/2;
        for(int i=0; i<nums.size(); i++){
            n= max(nums[i], n);
            s.insert(nums[i]);
            arraySum+= nums[i];
        }
        
        for(auto a: s){
            calculatedSum += a;
        }
        missingnum = expectedSum - calculatedSum;
        repeatednum = arraySum - calculatedSum; 
      
        return {repeatednum, missingnum};
    }
};