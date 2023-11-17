class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>mp;
        for(int i=0; i<t.length(); i++){
            mp[t[i]]++;
        }
        int reqCount= t.length();
        int i=0, j=0;
        int minWinSize=INT_MAX;
        int start_i=0;
        while(j<s.length()){
            char ch= s[j];
            if(mp[ch]>0){
                reqCount--;
            }
            mp[ch]--;
            
            // Start shrinking window 
            while(reqCount==0){
                int currWinSize=j-i+1;
                if(minWinSize>currWinSize){
                    minWinSize = currWinSize;
                    start_i= i;
                }
                
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    reqCount++;
                }
                i++;
            }
            j++;
        }

        return minWinSize==INT_MAX? "": s.substr(start_i, minWinSize);
    }
};