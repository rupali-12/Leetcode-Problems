class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        map<int, vector<int>>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
            
        }
        
        vector<long long>ans(nums.size(), 0);
       for(auto m: mp){
           vector<int>v = m.second;
           
           // calculate total sum
           long long sum=0;
           for(int a:v) sum+= a;
           
           // calculate prefix 
           long long currsum=0, restsum=0;
           for(int i=0; i<v.size(); i++){
               restsum = sum - currsum - v[i];
               long long sumleft= (v[i]*(long long)(i)) - currsum;
               long long sumright = restsum- (v[i]*(v.size()-1-i));
               
               ans[v[i]] =  sumleft + sumright;  // actually v[i] stores index where the value occured   
               currsum+= v[i];
           }
       }
        return ans;
    }
};