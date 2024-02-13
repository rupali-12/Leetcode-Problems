class Solution {
public:
    bool isPalindrome(string str){
        string temp= str;
        reverse(str.begin(), str.end());
        return temp==str;
    }
    string firstPalindrome(vector<string>& words) {
        string ans="";
        for(int i=0; i<words.size(); i++){
            if(isPalindrome(words[i])){
                ans= words[i];
                break;
            }
        }
        return ans;
    }
};