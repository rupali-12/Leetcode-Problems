class Solution {
public:
    int minMoves2(vector<int>& nums) {
        //  // Approach-1 >.find mid and then ass the absolute value of difference between the vaue at each index and the middle value 
        // int n= nums.size();
        // sort(nums.begin(), nums.end());
        // int mid =n/2;
        // int sum=0;
        // for(int i=0; i<mid; i++){
        //     sum+= abs(nums[mid]- nums[i]);
        //     cout<<sum<<" ";
        // }
        //  for(int i=mid+1; i<n; i++){
        //     sum+= abs(nums[mid]- nums[i]);
        //        cout<<sum<<" ";
        // }
        // return sum;
        
            // Approach-2> using pointer approach/
        int n= nums.size();
        sort(nums.begin(), nums.end());
        int s=0,e= n-1;
        int sum=0;
        while(s<e){
            sum+= nums[e]-nums[s];
            s++; e--;
        }
        return sum;
    }
};