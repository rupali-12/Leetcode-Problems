class Solution {
public:
    bool isArithmetic(vector<int>&temp, int diff){
        for(int i=2; i<temp.size(); i++){
            if(temp[i]-temp[i-1]!=diff) return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
       int n= nums.size(), m = l.size();
        vector<bool>ans(m);
        for(int i=0; i<m; i++){
            int len = r[i]-l[i]+1;
            
            // vector<int>temp(len+1); int k=0;
            // for(int j= l[i]; j<=r[i]; j++){
            //     temp[k++]= nums[j];
            // }
            
             vector<int> temp(len);

        for (int j = l[i]; j <= r[i]; ++j) {
            temp[j - l[i]] = nums[j];
        }
            
            sort(temp.begin(), temp.end());
            int diff = temp[1]-temp[0];
            if(isArithmetic(temp, diff)){
                ans[i]= true;
            }
            else{
                ans[i]= false;
            }
        }
        return ans;
    }
};