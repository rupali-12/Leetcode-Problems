class Solution {
public:
    string minWindow(string s, string t) {
       if(t.length()>s.length()) return "";
        int minWinSize=INT_MAX, i=0, j=0, start_i=0;
        unordered_map<char, int>mp;
        for(auto a: t){
            mp[a]++;
        }
        int reqCount= t.length();
        while(j<s.length()){
            char ch = s[j];
            if(mp[ch]>0){    //  it is required so take from map and decrease its count
                reqCount--;
            }
            mp[ch]--;
            
            // shrink window 
            while(reqCount==0){
                int currWinSize=j-i+1;
                if(minWinSize>currWinSize){
                    minWinSize= currWinSize;
                    start_i = i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    reqCount++;
                }
                i++;
            }
            j++;
        }
        return minWinSize==INT_MAX ? "": s.substr(start_i, minWinSize);
    }
};

