class Solution {
public:
    int maximumLength(string s) {
        map<pair<char, int>, int>mp;
        
        for(int i=0; i<s.length(); i++){
            char currchar=  s[i];
            int l=0;
            for(int j=i; j<s.length(); j++){
                if(currchar==s[j]){
                    l++;
                    mp[{currchar, l}]++;
                }
                else{
                    break;
                }
            }
        }
        int ans=-1;
        for(auto it:mp){
            int len = it.first.second;
            int freq=it.second;
            if(freq>=3 && len>ans){
                ans= len;
            }
        }
        return ans;
    }
};