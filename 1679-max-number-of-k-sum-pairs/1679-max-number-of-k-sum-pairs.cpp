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
       unordered_map<int,int>mp;
        for(auto num: nums){
            if(mp.count(k-num)){
                total++;
                mp[k-num]--;
                if(mp[k-num]==0){
                    mp.erase(k-num);
                }
            }
            else{   // if num not present in map then insert it 
                mp[num]++;
            }
        }
        return total;
    }
};