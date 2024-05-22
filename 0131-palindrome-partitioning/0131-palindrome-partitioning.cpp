class Solution {
public:
    bool isPalindrome(string s){
        for(int i=0; i<s.length()/2; i++){
            if(s[i]!=s[s.length()-i-1]) return false;
        }
        return true;
    }
    
    void solveRec(string s, int i, vector<vector<string>>&ans, vector<string>path){
        if(i==s.length()){
            ans.push_back(path);
        }
        
        for(int j=i; j<s.length(); j++){
            if(isPalindrome(s.substr(i, j-i+1))){
               path.push_back(s.substr(i, j-i+1));
                solveRec(s, j+1, ans, path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        solveRec(s, 0, ans, path);
        return ans;
    }
};