class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
       //  // Approach-1: Brute force (TLE for larger test cases )
       // vector<int>ans;
       //  for(int i=0;i<nums.size(); i++){
       //       int sum=0;
       //      for(int j=0; j<nums.size(); j++){
       //          sum+=abs( nums[i]-nums[j]);
       //      }
       //      ans.push_back(sum);
       //  }
       //  return ans;
        
        // Approach-2: Optimized 
          int n= nums.size();
        vector<int>ans(n);
       vector<int>prefix(n, 0);
        vector<int>suffix(n, 0);
        
        // calculate prefix and suffix 
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i-1];
            suffix[n-i-1] = suffix[n-i] + nums[n-i];
        }
        
      for(int i=0; i<n; i++){
          int temp = (nums[i]*i) - prefix[i] +suffix[i] - (nums[i]*(n-i-1));
          ans[i] =temp;
          
      }
  
        return ans;
    }
};