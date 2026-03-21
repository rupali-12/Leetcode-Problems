class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Inititalise two pointes 
        int slow= nums[0];
        int fast= nums[nums[0]];

        // Find intersection of two runners 
        while(slow!=fast){
          slow= nums[slow];
          fast= nums[nums[fast]];
        }

        // find entrance to the cycle 
        slow= 0;
        while(slow!=fast){
            slow= nums[slow];
            fast= nums[fast];
        }
        return slow;
    }
};

// slow=1  3 2 4    0 1 3 2
// fast= 3 4 4 4    4 2 4 2