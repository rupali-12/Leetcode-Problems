class Solution {
public:
    int n;
    int sumDigits(int num){
        int sum=0;
        while(num>0){
            sum+= num%10;
            num/=10;
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        n = nums.size();
        for(int i=0; i<n; i++){
            if(sumDigits(nums[i]) == i) return i;
        }
        return -1;
    }
};