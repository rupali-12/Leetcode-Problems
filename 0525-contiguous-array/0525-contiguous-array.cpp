class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int mxlength= 0;
        unordered_map<int,int>mp;
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0) sum--;
            else sum++;
            if(mp.find(sum)!=mp.end()){
                mxlength = max(mxlength, (i-mp[sum]));
            }
            else if(sum==0){
               mxlength = max(mxlength, (i+1));
            }
            else{
            mp[sum]= i;  
            }
        }
        return mxlength;
    }
};