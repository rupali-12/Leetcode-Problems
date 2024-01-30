class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(int i=0; i<tokens.size(); i++){
            string temp= tokens[i];
            
            if(temp=="+"){
                int second_op = s.top();
                s.pop();
                int first_op= s.top();
                s.pop();
                s.push(first_op + second_op);
            }
            else if(temp=="-"){
                int second_op = s.top();
                s.pop();
                int first_op= s.top();
                s.pop();
                s.push(first_op - second_op);
            }
            else if(temp=="*"){
                int second_op = s.top();
                s.pop();
                int first_op= s.top();
                s.pop();
                s.push(first_op * second_op);
            }
            else if(temp=="/"){
                int second_op = s.top();
                s.pop();
                int first_op= s.top();
                s.pop();
                s.push(first_op / second_op);
            }
            else{
                int num = stoi(temp);
                s.push(num);
            }
        }
        return s.top();
    }
};