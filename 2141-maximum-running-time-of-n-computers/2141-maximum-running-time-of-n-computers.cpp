class Solution {
public:
    typedef long long ll;
    bool isPossible(vector<int>&batteries, ll mid_minutes, int n){
        ll sum=0;
        ll target_sum = mid_minutes*n;
        for(int i=0; i<batteries.size(); i++){
            sum+= min(ll(batteries[i]), mid_minutes);
            if(sum >= target_sum){
                return true;
            }
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        ll l= *min_element(begin(batteries), end(batteries));
        ll total_sum = 0;
        for(int i=0; i<batteries.size(); i++){
            total_sum+= batteries[i];
        }

        ll r = total_sum/n;
        ll result=0;
        while(l<=r){
            ll mid_minutes = l + (r-l)/2;
            if(isPossible(batteries, mid_minutes, n)){
                result = mid_minutes;
                l = mid_minutes +1;
            }
            else{
                r = mid_minutes -1;
            }
        }
        return result;
    }
};