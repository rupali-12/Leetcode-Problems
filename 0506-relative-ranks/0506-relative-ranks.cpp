class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int, int>mp;
        for(int i=0; i<score.size(); i++){
            mp[score[i]]= i;
        }
        
        sort(score.begin(), score.end(), greater<int>());
       vector<string>ans(score.size());
        
        for(int i=0; i<score.size(); i++){
            int idx= mp[score[i]];
            if(i==0) ans[idx] = "Gold Medal";
            else if(i==1) ans[idx] = "Silver Medal";
            else if(i==2) ans[idx] = "Bronze Medal";
            else ans[idx] = to_string(i+1);
        }
        return ans;
    }
};