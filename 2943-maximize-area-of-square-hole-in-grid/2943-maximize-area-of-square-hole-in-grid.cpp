class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // sort the inputs 
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxConsecutiveHBars = 1; //length of lengest horizontal bar
        int maxConsecutiveVBars = 1; //length of lengest vertical bar

        // find longest horizontal bar 
        int currConsecutiveHBars =1;
        for(int i=1; i<hBars.size(); i++){
            if(hBars[i]-hBars[i-1] ==1){
                currConsecutiveHBars++;
            }
            else{
                currConsecutiveHBars=1;
            }
            maxConsecutiveHBars = max(maxConsecutiveHBars, currConsecutiveHBars);
        }

        // find longest vertical bar 
        int currConsecutiveVBars =1;
        for(int i=1; i<vBars.size(); i++){
            if(vBars[i]-vBars[i-1] ==1){
                currConsecutiveVBars++;
            }
            else{
                currConsecutiveVBars=1;
            }
            maxConsecutiveVBars = max(maxConsecutiveVBars, currConsecutiveVBars);
        }

        int side = min(maxConsecutiveHBars, maxConsecutiveVBars) +1;
        return side*side;
    }
};