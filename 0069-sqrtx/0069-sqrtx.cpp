class Solution {
public:
// if you want precision after decimal 
double morePrecision(int n, int prec, int tempSol){
    double factor=1;
    double ans= tempSol;
    for(int i=1; i<=prec; i++){
        factor = factor/10;
        for(double j=ans; j*j<n; j+=factor){
           ans=j;
        }
    }
    return ans;
}
int sqrt(int N){
      int s=0, e= N;
 long long mid = s+(e-s)/2;
    int ans=-1;
    if(N==0 || N==1){
        return N;
    }
while(s<=e){
    if(mid*mid==N){
        return mid;
    }
    else if(mid*mid < N){
        ans=mid;
        s= mid+1;
    }
    else{
        e =mid-1;
    }
    mid= s+(e-s)/2;
}
    return ans;
}

int  mySqrt(int N)
{
    int tempSol = sqrt(N);
    
    return morePrecision(N, 3, tempSol);
}

};