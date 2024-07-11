class Solution {
public:
    string reverseParentheses(string str) {
        vector<string>st;
        for(int i=0; i<str.length(); i++){
            if(str[i]=='('){
                st.push_back("(");
            }
            else if(str[i]==')'){
                string rev="";
                while(st.size()>0 && st.back()!="("){
                    reverse(st.back().begin(), st.back().end());
                    rev+= st.back();
                    st.pop_back();
                }
                st.pop_back(); // to remove "("
                st.push_back(rev);
            }
            else{
                st.push_back(string(1, str[i]));
            }
        }
       string ans = accumulate(st.begin(), st.end(), string());
        return ans;
    }
};