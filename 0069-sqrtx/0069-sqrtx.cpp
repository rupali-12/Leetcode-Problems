class Solution {
public:
    int mySqrt(int x) {
int s=0, e=x-1;
      long long int ans=-1;
      long long int mid= s+(e-s)/2;
        if(x==0 || x==1) return x;
        while(s<=e){
          long long int sq= mid*mid;
            if(sq==x){
                return mid;
            }
            else if(sq<x){
                ans= mid;
                s= mid+1;
            }
            else{
                e= mid-1;
            }
            mid= s+(e-s)/2;
        }
        return ans;
    }
};



       

       