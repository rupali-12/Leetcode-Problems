class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int minTime = min(abs(fx-sx), abs(fy-sy)) + abs(abs(fy-sy)-abs(fx-sx));
        
        if(sx==fx && sy==fy && t==1) return false;
        if(minTime <= t) return true;
        return false;
    }
};