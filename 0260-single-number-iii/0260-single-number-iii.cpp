class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n= nums.size();
        long long xorNos = 0;
        for(auto num: nums){
            xorNos^= num;
        }
        
        int lowerbit = xorNos & (-xorNos);   // find lower set bit 
        vector<int>ans(2, 0);
        
        for(auto num: nums){
            if((lowerbit&num)==0){   // if lowerset bit of num is not set i.e =0
                ans[0]^= num;
            }
            else{   // if lower set bit of num is set
                ans[1]^= num;
            }
        }
        return ans;
    }
};