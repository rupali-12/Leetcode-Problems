class Solution {
public:
     bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++; j--;
        }
        return true;
    }
    void solveRec(string s, int i, vector<vector<string>>&ans, vector<string>&path){
        if(i==s.length()){
            ans.push_back(path);
         
        }
        for(int j= i; j<s.length(); j++){
          if(isPalindrome(s, i, j)){
               path.push_back(s.substr(i, j-i+1));
            solveRec(s, j+1, ans, path);
            path.pop_back();
          }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        int i=0;
        
        // Approach-1: Recursion 
        solveRec(s, i, ans, path);
        return ans;
    }
};