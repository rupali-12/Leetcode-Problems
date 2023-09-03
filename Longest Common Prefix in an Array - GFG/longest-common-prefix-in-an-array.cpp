//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int n)
    {
        // your code here
        string result = arr[0];
    int len = result.length();
 
    // Iterate for rest of element in string.
    for (int i = 1; i < n; i++) {
        // .find() return index of that substring from
        // string.
        while (arr[i].find(result) != 0) {
 
            // update matched substring prefx
            result = result.substr(0, len - 1);
            len--;
 
            // check for empty case. direct return if true..
            if (result.empty()) {
                return "-1";
            }
        }
    }
    return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends