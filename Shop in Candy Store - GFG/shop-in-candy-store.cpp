//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        vector<int>ans;
       sort(candies, candies+N);
        int mnAmt=0, mxAmt=0;
        // For minimum 
        int buyMn=0;
        int freeMn =N-1;
        while(buyMn<=freeMn){
            mnAmt+= candies[buyMn];
            buyMn++;
            freeMn = freeMn- K;
        }
        ans.push_back(mnAmt);
        
        int buyMx=N-1;
        int freeMx =0;
        while(buyMx>=freeMx){
            mxAmt+= candies[buyMx];
            buyMx--;
            freeMx = freeMx+ K;
        }
        ans.push_back(mxAmt);
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
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends