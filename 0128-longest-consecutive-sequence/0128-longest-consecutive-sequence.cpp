class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n= nums.size();

    //     // Approach 1: Sorting 
    //     sort(nums.begin(), nums.end());
    //     int longestSub=0, lastSmallest=INT_MIN, currCount=0;
    //     for(int i=0; i<n; i++){
    //         // case of consecutive
    //         if((nums[i]-1)==lastSmallest){
    //            currCount++;
    //            lastSmallest = nums[i];
    //         }
    //         // case of non consecutive 
    //         else if(lastSmallest != nums[i]){
    //            currCount=1;
    //            lastSmallest = nums[i];
    //         }
    //         longestSub = max(longestSub, currCount);
    //     }
    //    return longestSub;

    // Approach 2: using Set 
    if(n==0) return 0;
    set<int>st;
    for(int num: nums){
        st.insert(num);
    }

    int longestSub=1;
    for(int num: st){
        if(st.find(num-1)!=st.end()){
            continue;
        }
        else{
            int currNum=num;
            int currCount=1;
            while(st.find(currNum+1)!=st.end()){
                currNum++;
                currCount++;
            }

            // calculate longest length
            longestSub = max(longestSub, currCount);
        }
    }
        return longestSub;
    }
};