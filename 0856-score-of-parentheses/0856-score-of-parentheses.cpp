class Solution {
public:
    int scoreOfParentheses(string s) {
        int score=0;
        stack<int>st; //track score
        st.push(0);
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                st.push(0);   // if ( then insert 0
            }
            else{
                int top= st.top();
                st.pop();
                int val=0;
                if(top>0){    // if st.top != '('
                    val = 2*top;
                }
                else{        // st.top == '('
                    val=1;   
                }
                st.top()+= val;
            }
        }
        return st.top();
    }
};

