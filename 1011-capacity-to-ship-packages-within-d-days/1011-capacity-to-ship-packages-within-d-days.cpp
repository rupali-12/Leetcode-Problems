class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int res =INT_MIN;
        for(int i=0; i<n; i++){
            if(res<weights[i]){
                res= weights[i];
            }
        }
        // find sum >>>>
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=weights[i];
        }

        int s=res, e=sum, ans=-1;
        while(s<=e){
            int dayscount=1, weightSum=0;
            int mid = s+(e-s)/2;
            for(int i=0; i<n; i++){
                weightSum+=weights[i];
                if(weightSum>mid){
                    dayscount++;
                    weightSum=weights[i];
                }
            }
            if(dayscount<=days){
                ans = mid;
                e= mid-1;
            }
            else{
                s= mid+1;
            }
        }
        return ans;
    }
};