class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
       //  // sorting 
       // int i=0, j= nums.size()-1;
       //  int count=0;
       //  sort(nums.begin(), nums.end());
       //  while(i<j){
       //      int sum= nums[i]+nums[j];
       //      if(sum==k){
       //          count++; 
       //          i++;
       //          j--;
       //      }
       //      else if(sum<k){
       //          i++;
       //      }
       //      else{
       //          j--;
       //      }
       //  }
       //  return count;
        
        // Hashmap
         int total=0;
        map<int,int>mp;
        for(auto a: nums){
            mp[a]++;
        }
        
        for(auto num: nums){
            if(mp.find(k-num)!=mp.end()){
                total++;
                mp[k-num]--;
                if(mp[k-num]==0){
                    mp.erase(k-num);
                }
            }
        }
        
        // but in this (1, 4) and (4,1) ccount we need to divide total/2
        return floor(total/2);
    }
};