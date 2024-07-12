class Solution {
public:
    string removeSubstr(string &s, string &removedStr){
        stack<char>st;
        for(auto &ch: s){
            if(ch==removedStr[1] && !st.empty() && st.top()==removedStr[0]){
                st.pop();
            }
            else{
                st.push(ch);
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
    int maximumGain(string s, int x, int y) {
        
        // approach-1 using arrays
        int n=s.length();
        int score=0;
        
        string maxStr= (x>y)? "ab":"ba";
        string minStr= (x<y)?"ab":"ba";
        
//         First Pass
        string temp_first = removeSubstr(s, maxStr);
        int L1= temp_first.length();
        
        int charRemoved = n-L1;
        score+= (charRemoved/2)* (max(x, y));   // charRemoved/2 becoz to count pair
        
        // Second pass
         string temp_second = removeSubstr(temp_first, minStr);
         int L2 = temp_second.length();
        
         charRemoved = L1-L2;
        score+= (charRemoved/2)* (min(x, y));   
        
        return score;
    }
};