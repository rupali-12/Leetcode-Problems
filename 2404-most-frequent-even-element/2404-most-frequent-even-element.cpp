class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int>mp;
        for(auto num: nums){
           if(num%2==0){
                mp[num]++;
           }
        }
        
     int ans= -1;
         int val= 0;
    
        for(auto a: mp){
            
             if(a.second > val){
                 ans = a.first;
                val= a.second;
             }

        }
        
        return ans;
    }
    

    
};