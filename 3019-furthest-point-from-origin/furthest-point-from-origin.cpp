class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countL=0, countR=0;
        int n= moves.length();
        for(int i=0; i<moves.length(); i++){
            if(moves[i]=='L') countL++;
            else if(moves[i]=='R') countR++;
        }
        if(countL >= countR){
            countL+= n - countL -countR; 
        }
        else{
            countR += n - countL -countR;
        }
        return abs(countL - countR);
    }
};

// Ex -1
// total = 7
// countL =2
// countR =2
// total = total - countL -countR;

// Ex -2
// total = 7
// countL =2
// countR =1
// total = total - countL -countR;