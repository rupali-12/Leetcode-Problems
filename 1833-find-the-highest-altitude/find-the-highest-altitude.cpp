class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highestAltitude = gain[0];
        int prefixSum = gain[0];
        for(int i=1; i<gain.size(); i++){
          prefixSum+= gain[i];
          highestAltitude = max(highestAltitude, prefixSum);
        }
        return highestAltitude < 0? 0: highestAltitude;
    }
};