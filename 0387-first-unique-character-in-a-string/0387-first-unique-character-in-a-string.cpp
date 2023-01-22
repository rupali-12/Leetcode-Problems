class Solution {
public:
    int firstUniqChar(string s) {
 map<char, int>mp;
   for(long long int i=0; i<s.length(); i++){
       mp[s[i]]++;
   }
   for(int i=0; i<s.size(); i++){
     if (mp[s[i]] == 1) {
       return i;
     }
   }
   return -1;
    }
};