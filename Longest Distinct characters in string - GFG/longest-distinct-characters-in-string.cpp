//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
     int left=0, right=0;
        unordered_map<char, int>mp;
        int len=0;
        int n= s.length();
        while(right<n){
            if(mp.find(s[right])!=mp.end()){
                 left= max(left, mp[s[right]]+1);
            }
            
            // update occurence of char 
            mp[s[right]]= right;
            len = max(len, right-left+1);
            right++;
        }
        return len;
}