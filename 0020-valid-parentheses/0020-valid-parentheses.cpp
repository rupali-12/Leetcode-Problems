class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int i=0;
        while(i<s.length()){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(!st.empty() && ((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='['))){
                    st.pop();
                }
                else return false;
            }
            i++;
        }
        return st.empty();
    }
};