class Solution {
public:
    string minWindow(string s, string t) {
        int n= s.length();
        if(t.length() > n){
            return "";
        }

        unordered_map<char, int>mp;
        int minWindowSize=INT_MAX;
        int start_i=0, i=0, j=0;
        int requiredCount=t.length();

        // store t in mp
        for(auto c: t){
            mp[c]++;
        }

        while(j<n){
            char ch = s[j];
            if(mp[ch]>0){
                requiredCount--;
            }
            mp[ch]--;

            // case when shrink
            while(requiredCount==0){
                int currentWindowSize= j-i+1;
                if(minWindowSize > currentWindowSize){
                    minWindowSize = currentWindowSize;
                    start_i =i;  // this store start of min window
                }
                mp[s[i]]++;  // increase as it required we shrink
                if(mp[s[i]]>0){
                    requiredCount++;  // if any char count>0 it means we required as non required will always be negative count
                }
                i++;
            }
            j++;
        }
       return minWindowSize==INT_MAX? "": s.substr(start_i, minWindowSize);
    }
};