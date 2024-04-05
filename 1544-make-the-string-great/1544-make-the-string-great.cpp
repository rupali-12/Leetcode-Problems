class Solution {
public:
    string makeGood(string s) {
        int n= s.length();
        stack<char>st;
        for(int i=0; i<s.length(); i++){
            if(!st.empty() && ((st.top()-32)==s[i] || (st.top()+32)==s[i])){
                st.pop();
            }
            else{
              st.push(s[i]);    
            }
        }
        string ans="";
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};