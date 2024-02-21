class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        // Approach-1: Brute force 
       //  int shiftCount=0;
       // while(left!=right){
       //     left= left>>1;
       //     right= right>>1;
       //     shiftCount++;
       // }
       //  int ans = left<<shiftCount;
       //  return ans;
        
        // Approach-2: Optimized 
        while(right>left){
            right= right&(right-1);
        }
        return right;
    }
};