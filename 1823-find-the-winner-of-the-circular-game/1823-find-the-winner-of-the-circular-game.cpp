class Solution {
public:
    int findTheWinner(int n, int k) {
        
        // Approach-1: Brute Force 
        vector<int>circle(n);
        for(int i=1; i<=n; i++){
            circle[i-1] = i;
        }
        
        int currIdx=0;
        while(circle.size()>1){
            int nextAfterRemove= (currIdx + k + -1)%circle.size();
            circle.erase(circle.begin() + nextAfterRemove);
            currIdx = nextAfterRemove;
        }
        return circle[0];
    }
};