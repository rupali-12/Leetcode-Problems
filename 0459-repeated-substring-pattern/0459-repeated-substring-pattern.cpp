class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t=s;
        for(int i=0; i<s.length()-1; i++){
            char ch=s[0];   // store the first character
            s.erase(0,1);   // remove first character
            s.push_back(ch);   // append that stored character
            
            if(t==s){
                return true;
            }
        }
        return false;
    }
};