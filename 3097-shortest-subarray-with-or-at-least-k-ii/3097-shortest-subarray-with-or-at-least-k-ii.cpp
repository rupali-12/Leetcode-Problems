class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> fre(32, 0);
        int curr = 0;
        int i = 0, j = 0;
        int ans = INT_MAX;
        while(j<nums.size()){
            curr|=nums[j];
            int n = 1;
            for(int l = 0; l<32; l++){
                if(n & nums[j]){
                    fre[l]++;
                }
                n = n<<1;
            }
            j++;

            while(curr>=k && i<j){
                ans = min(ans, j-i);
                int n = 1;
                for(int l = 0; l<32; l++){
                    if(n & nums[i]){
                        fre[l]--;
                        if(fre[l] == 0){
                            curr = curr - n;
                        }
                    }
                    n = n<<1;
                }
                i++;
            }
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};