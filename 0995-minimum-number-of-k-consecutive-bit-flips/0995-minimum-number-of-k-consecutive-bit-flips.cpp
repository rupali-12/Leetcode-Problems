class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n= nums.size();
        int flips=0, flipCountFromPastFori=0;
        vector<bool>isFlipped(n, false);
        
        for(int i=0; i<n; i++){
             if(i>=k && isFlipped[i-k]==true){
                flipCountFromPastFori--;
            }
                        
            if(flipCountFromPastFori % 2 == nums[i]){  // flip it at index i
                
                 if(i+k >n) return -1;
                
                flipCountFromPastFori++;
                isFlipped[i]=true;
                flips++;
            }
        }
        
        return flips;
    }
};