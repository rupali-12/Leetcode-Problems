class Solution {
public:
    long long countTrips(vector<int>&time, long long  mid){

        long long  total=0;
         for(long long i=0; i<time.size(); i++){
             total+= mid/time[i];
         }
        return total;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
     long long s=0, e=100000000000000, ans =e;
        while(s<=e){
           long long mid = s+(e-s)/2;
            long long total = countTrips(time, mid);
            if(total>=totalTrips){
                ans= min(ans, mid);
                e = mid-1;
            }
            else{
                s= mid+1;
            }
        }
        
        return ans;
    }
};