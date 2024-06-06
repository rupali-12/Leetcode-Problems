class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n= hand.size();
        unordered_map<int, int>mp;
        if(n<groupSize || (n%groupSize)!=0) return false;
        for(auto a: hand) mp[a]++;
        sort(hand.begin(), hand.end());
        
        for(auto i:hand){
            if(mp[i]==0) continue;
            bool flag=true;  // determine whether possible to make or not
            for(int k=0; k<groupSize; k++){
                if(mp[i+k]<=0){
                    flag=false;
                    break;
                }
                else{
                    mp[i+k]--;
                }
            }
            if(!flag) return false;
        }
        return true;
    }
};