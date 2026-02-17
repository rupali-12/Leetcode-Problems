class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        // constant TC & SC
        vector<string>ans;
        for(int HH=0; HH<12; HH++){
           for(int MM=0; MM<=59; MM++){
           if(__builtin_popcount(HH) + __builtin_popcount(MM) == turnedOn){
             string hour = to_string(HH);
             string minutes = (MM<10 ? "0":"") + to_string(MM);
             ans.push_back(hour +  ":" + minutes);
           }
           }
        }
        return ans;
    }
};