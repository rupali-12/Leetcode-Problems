//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        string ans= "";
        int i= S.length()-1;
        string temp="";
        while(i>=0){
            if(S[i]=='.'){
                reverse(temp.begin(), temp.end());
                ans+= temp;
                temp="";
                ans+= '.';
            }
            else{
                temp.push_back(S[i]);
            }
            i--;
        }
        
        // handle last word 
        reverse(temp.begin(), temp.end());
         ans+= temp;
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends