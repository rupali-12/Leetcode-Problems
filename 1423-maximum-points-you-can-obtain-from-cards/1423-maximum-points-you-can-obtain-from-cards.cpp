class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int mxScore=0;
        int n= cardPoints.size();
        vector<int>cumSum(n);
        cumSum[0]= cardPoints[0];
        for(int j=1; j<n; j++){
            cumSum[j]= cumSum[j-1] + cardPoints[j];
        }
        if(cardPoints.size()==k){
            return cumSum[n-1];
        }
        int i=0;
        while(i<=k){
            int ans;
            if(i==0){
                // ans is storing the sum of elements which we not choose to make mxScore 
                ans= cumSum[n-1]- cumSum[i+n- k-1];
            }
            else{
                ans= cumSum[n-1]- (cumSum[i+n- k-1]- cumSum[i-1]);
            }
             
            i++;
            
            mxScore= max(mxScore, ans);
        }
        
        return mxScore;
    }
};