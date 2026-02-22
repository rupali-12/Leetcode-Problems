class Solution {
public:
    int binaryGap(int n) {
        int currPos = 0, prevPos=-1;
        int ans=0;
        while(n!=0){
           int currBit = n&1;
            n= n>>1;
            if(currBit==1){
                if(prevPos!=-1){
                    ans = max(ans, (currPos-prevPos));
                }
                prevPos = currPos;
            }
           currPos++;
        }
        return ans;
    }
};