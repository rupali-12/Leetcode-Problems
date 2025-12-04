class Solution {
public:
    int countCollisions(string directions) {
        int n= directions.length();
        int l=0, r= n-1;
        //  Remove all cars going left which iscoming from far left (leading L's) 
        while(l<n && directions[l]=='L') l++;

        //  Remove all cars going right which is coming from far right (trailing R's) 
        while(r>=0 && directions[r]=='R') r--;

        int collisions=0;
        for(int i=l; i<=r; i++){
            if(directions[i]!='S'){
                collisions++;
            }
        }
        return collisions;
    }
};