class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        stack<int>st;
        st.push(-1);
        int i=0;
        int ans=0;
        while(i<n){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    ans=max(ans, (i-st.top()));
                }
            }
            i++;
        }
        return ans;
    }
};