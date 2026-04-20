class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int mxAns=0, n=colors.size();
        for(int i=0; i<n-1; i++){
           for(int j=i+1; j<n; j++){
              if(colors[i]!=colors[j]){
                mxAns = max(mxAns, abs(j-i));
              }
           }
        }
        return mxAns;
    }
};