class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n= tokens.size();
        for(int i=0; i<n; i++){
            string token =tokens[i];
            int second_op, first_op;
            if(token=="+"){
              second_op = st.top();
              st.pop();
              first_op=st.top();
              st.pop();
              st.push(first_op + second_op);
            }
            else if(token=="-"){
 second_op = st.top();
              st.pop();
              first_op=st.top();
              st.pop();
              st.push(first_op - second_op);
            }
            else if(token=="*"){
 second_op = st.top();
              st.pop();
              first_op=st.top();
              st.pop();
              st.push(first_op * second_op);
            }
            else if(token=="/"){
 second_op = st.top();
              st.pop();
              first_op=st.top();
              st.pop();
              st.push(first_op / second_op);
            }
            else{
                int num= stoi(token);
                st.push(num);
            }
        }
        return st.top();
    }
};