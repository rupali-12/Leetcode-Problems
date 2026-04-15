class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans=INT_MAX;
        int n = words.size();
        for(int i=0; i<n; i++){
            if(words[i]==target){
                int straightDist = abs(i-startIndex);
                int circularDist = n - straightDist;
                ans = min(ans, min(straightDist, circularDist));
            }
        }
          return ans==INT_MAX? -1: ans;
    }
};