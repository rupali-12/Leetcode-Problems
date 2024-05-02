class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        // set<int>st(spaces.begin(), spaces.end());
        int lastIndex=0;
        string ans=s.substr(0, spaces[lastIndex])+' ';
        for(int i=1; i<spaces.size(); i++){
           int len= spaces[i] - spaces[lastIndex];
             ans+= s.substr(spaces[lastIndex], len)+' ';
            lastIndex= i;
        }
        // handle last substring 
        ans+= s.substr(spaces[lastIndex]);
        return ans;
    }
};