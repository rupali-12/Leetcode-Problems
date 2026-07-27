class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Approach 1: Sorting
       string ans="";
       int n = strs.size();
       sort(strs.begin(), strs.end());
       string first = strs[0];
       for(int i=0; i<first.length(); i++){
          if(strs[0][i]==strs[n-1][i]){
            ans+= strs[0][i];
          }
          else{
            break;
          }
       }
       return ans;

    }
};