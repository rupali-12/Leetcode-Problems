class Solution {
public:
    bool isPalindrome(string s) {
        // string temp="";
        for(int i=0; i<s.length();i++){
          if(!isalnum(s[i])){
              s.erase(i, 1);
              i--;
          }
        }
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(int i=0; i<s.length()/2; i++){
            if(s[i]!=s[s.length()-i-1]){
                return false;
            }
        }
        return true;
    }
};