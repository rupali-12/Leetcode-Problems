//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int>ans;
        int count=0;
        int startRow=0, startCol=0, endRow= r-1, endCol= c-1;
        while(count< r*c){
            // start row 
            for(int col=startCol; col<=endCol && count<r*c; col++){
                ans.push_back(matrix[startRow][col]);
                count++;
            }
            startRow++;
            // end col 
            for(int row=startRow; row<=endRow && count<r*c; row++){
                ans.push_back(matrix[row][endCol]);
                count++;
            }
            endCol--;
            // start col 
            for(int col=endCol; col>=startCol && count<r*c; col--){
                ans.push_back(matrix[endRow][col]);
                count++;
            }
            endRow--;
            // start col 
           for(int row=endRow; row>=startRow && count<r*c; row--){
                ans.push_back(matrix[row][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends