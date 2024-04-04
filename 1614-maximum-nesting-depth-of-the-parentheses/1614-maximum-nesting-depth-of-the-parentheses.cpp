class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int max_depth= 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                st.pop();
            }
            max_depth= max(max_depth, (int)st.size());
        }
        return max_depth;
    }
};