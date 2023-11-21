class Solution {
public:
    int mod= 1e9 +7;
    int rev(int num){
        int revNum=0;
        while(num>0){
            int rem=num%10;
            revNum= revNum*10 + rem;
            num/=10;
        }
        return revNum;
    }
    int countNicePairs(vector<int>& nums) {
        int n= nums.size();
        int count=0;
       vector<int>v(n);
        for(int i=0; i<n;i++){
            int temp= nums[i]-rev(nums[i]);
           v[i]= temp;
        }
        
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            if(mp.find(v[i])!=mp.end()){
                count= count%mod+  mp[v[i]];
                mp[v[i]]++;
            }
            else{
                mp[v[i]]++;
            }
        }
        return count%mod;
    }
};