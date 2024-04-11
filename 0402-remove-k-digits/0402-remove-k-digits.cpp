class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        int n=num.length();
        // stack<char>st;
        vector<int>temp;
        for(int i=0; i<n; i++){
            while(!temp.empty() && temp.back()>num[i] && k>0){
                temp.pop_back();
                k--;
            }
            
            temp.push_back(num[i]);
        }
        
        while(k--){
            temp.pop_back();
        }
        
      for(const char ch: temp) {
          temp.pop_back();
          if(ch=='0' && ans.empty()) continue;
          ans+= ch;
      }
        return ans==""? "0": ans;
    }
};