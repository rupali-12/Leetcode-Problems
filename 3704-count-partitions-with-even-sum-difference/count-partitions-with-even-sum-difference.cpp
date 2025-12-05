class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int left= 0, n= nums.size();
        int right=0;
        for(int i=0; i<n; i++){
            right+= nums[i];
        }

        int ans=0;
        for(int i=0; i<n-1; i++){
            left+= nums[i];
            right-= nums[i];
            if(abs(left-right)%2==0){
                ans++;
            }
        }
        return ans;
    }
};
