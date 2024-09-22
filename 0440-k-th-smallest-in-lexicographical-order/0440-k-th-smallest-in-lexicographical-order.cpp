class Solution {
public:
    int countSteps(int curr, long n) {
        long steps = 0;
        long first = curr, last = curr;
        while (first <= n) {
            steps += min(last, n) - first + 1;
            first *= 10;
            last = last * 10 + 9;
        }
        return steps;
    }
    
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;  
        
        while (k > 0) {
            int steps = countSteps(curr, n);
            if (steps <= k) {
               
                curr++;
                k -= steps;  
            } else {
                curr *= 10;
                k--;  
            }
        }
        
        return curr;
    }
};
