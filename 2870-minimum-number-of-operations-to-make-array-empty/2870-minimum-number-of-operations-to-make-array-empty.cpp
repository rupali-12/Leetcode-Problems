class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        
        int ans=0;
        for (auto a : mp) {
            int count = a.second;
           if(count==1) return -1;
           if(count%3==0){
               ans+= count/3;
           }  
            else{    // when rem =1 or 2
                ans+= (count/3)+1;
            }
        }
        return ans;
    }
};