class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n =nums.size();
        vector<int>pre(n), suff(n), res(n);

        pre[0]=nums[0];
        for(int i=1; i<n; i++){
            pre[i]=max(pre[i-1], nums[i]);
        }

        suff[n-1]=nums[n-1];
        for(int i=n-2; i>=0; i--){
            suff[i]=min(suff[i+1], nums[i]);
        }

        res[n-1]=pre[n-1];

        for(int i=n-2; i>=0; i--){
            if(pre[i]>suff[i+1]){
                res[i]=res[i+1];
            }
            else{
                res[i]=pre[i];
            }
        }
        return res;
    }
};

