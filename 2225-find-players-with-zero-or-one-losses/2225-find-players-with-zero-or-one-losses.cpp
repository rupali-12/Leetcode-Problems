class Solution {
public:
    vector<int>listNotLostAnyMatch(vector<vector<int>>matches, map<int, int>mp){
        vector<int>ans;
        for(const auto& match:matches){
                if(mp.find(match[0])==mp.end()){
if (find(ans.begin(), ans.end(), match[0]) == ans.end()) {
                ans.push_back(match[0]);
            }
            }
        }
        return ans;
    }
     vector<int>listLostExactlyOneMatch(vector<vector<int>>matches, map<int, int>mp){
         vector<int>ans;
        for(auto match:matches){
                if(mp[match[1]]==1){
                ans.push_back(match[1]);
            }
        }
        return ans;
    }
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>answer;
        map<int, int>mp;
        for(auto match: matches){
             mp[match[1]]++;
        }
        
           vector<int>temp1 = listNotLostAnyMatch(matches, mp);
         sort(temp1.begin(), temp1.end());
           answer.push_back(temp1);
        
         vector<int>temp2 = listLostExactlyOneMatch(matches, mp);
         sort(temp2.begin(), temp2.end());
           answer.push_back(temp2);
       
        return answer;
    }
};