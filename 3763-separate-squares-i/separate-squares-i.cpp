class Solution {
public:
    double areaBelowMid(double mid, vector<vector<int>>& squares){
        double area = 0;
        for(auto &square: squares){
            double y = square[1], len = square[2];
        if(mid >= (y+len)){
           area+= len*len;
        }
        else if((mid>y) && (mid<(y+len))){
            area+= len*(mid-y);
        }
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea=0, ansY=0;
        double mn = INT_MAX, mx=INT_MIN;
        for(auto &square: squares){
            double len = square[2];
            totalArea += len* len;
            mn = min(mn, (double)square[1]);
            mx = max(mx, (double)square[1]+len);
        }

        double target = totalArea/2;
        double low = mn, high = mx;
        while(high - low > 1e-5){
            double mid = low + (high-low)/2;
            if(areaBelowMid(mid, squares) < target){
                low = mid;
            }
            else{
                ansY = mid;
                high= mid;
            }
        }
        return ansY;
    }
};