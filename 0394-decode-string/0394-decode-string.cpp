class Solution {
public:
    bool isDigit(char ch){
        if((ch-'0'>=0) && (ch-'0'<=9)){
            return true;
        }
        return false;
    }
    
    bool isAlphabet(char ch){
        if((ch-'a'>=0) && (ch-'a'<=25)){
            return true;
        }
        return false;
    }
    
    string decodeString(string s) {
       string ans="";
        stack<char>stChar;
        stack<int>stNum;
        int num=0;
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            string temp="";
           
        if(ch=='[' || isAlphabet(ch)){
            if(ch=='['){
                stNum.push(num);
                num=0;
            }
            stChar.push(ch);
        }
        else if(isDigit(ch)){
           num= num*10 + (ch-'0');
        }
        else{
            int num = stNum.top();
            stNum.pop();
             while(stChar.top()!='['){
                temp+= stChar.top();
                stChar.pop();
            }
            stChar.pop();   // to remove '['
            reverse(temp.begin(), temp.end());
            string res="";
            while(num>0){
                res+= temp;
                num--;
            }
            temp="";
            
            // push res in stChar again 
            for(int i=0; i<res.length(); i++){
                stChar.push(res[i]);
            }
        }   
        }
        while(!stChar.empty()){
            ans+= stChar.top();
            stChar.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};