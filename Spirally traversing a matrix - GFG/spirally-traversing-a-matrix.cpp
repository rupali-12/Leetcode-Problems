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
        int startRow=0, startCol=0, endRow=r-1, endCol=c-1;
        int count=0, total = r*c;
        while(count<total){
          for(int i=startCol; count<total && i<=endCol; i++){
              ans.push_back(matrix[startRow][i]);
               count++;
          }  
            startRow++;
             for(int j=startRow; count<total && j<=endRow; j++){
              ans.push_back(matrix[j][endCol]);
                  count++;
          }  
            endCol--;
             for(int i=endCol; count<total && i>=startCol; i--){
              ans.push_back(matrix[endRow][i]);
                  count++;
          }  
            endRow--;
              for(int j=endRow; count<total && j>=startRow; j--){
              ans.push_back(matrix[j][startCol]);
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