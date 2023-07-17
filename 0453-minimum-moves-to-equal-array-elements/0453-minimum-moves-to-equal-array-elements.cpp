class Solution {
public:
    int minMoves(vector<int>& nums) {
        // {1, 2, 3}= S
        // {2, 3, 3}(n-1)changes
        // {3, 4, 3}(n-1)changes
        // {4, 4, 4}(n-1)changes  x=4
            // m= total increment at first value =3
        // 1. we can write -> S + m*(n-1) = x*n
        // 2. min + m =x
        // m= x-min
        // S + mn - m = n*(m + min)
        // S - m = min*n
        // m = S - min*n  --> this we need to find the min no. of operation 
        
        int n= nums.size();
        sort(nums.begin(),nums.end());
        int mn= nums[0];
        int S= 0;
        for(auto a: nums){
            S+= a;
        }
        
        int minMoves= S - (n*mn);
        return minMoves;
    }
};