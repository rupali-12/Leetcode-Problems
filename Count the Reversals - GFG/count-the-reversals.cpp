//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends



int countRev (string s)
{
    // your code here
    
    // return 0 if length of string is odd
    if(s.length()%2!=0){
        return -1;
    }
    
    stack<char>st;
    for(int i=0; i<s.length(); i++){
        char ch =s[i];
        if(ch=='{'){
            st.push(ch);
        }
        else{
            // if closing braket encounterd and top of stack is openig bracket then pop it out 
            if(!st.empty() && st.top()=='{'){
               st.pop(); 
            }
            else{
                st.push(ch);
            }
        }
    }
    
    // After then count the number of opening and closing brackets and return ans
    int countOfOpenBracket =0;
    int countOfCloseBracket =0;
    while(!st.empty()){
        if(st.top()=='{'){
            countOfOpenBracket++;
        }
        else{
            countOfCloseBracket++;
        }
        st.pop();
    }
    
    int ans = ((countOfOpenBracket+1)/2 + (countOfCloseBracket+1)/2);
    return ans;
}