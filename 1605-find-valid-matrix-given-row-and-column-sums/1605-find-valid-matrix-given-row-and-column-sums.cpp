class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int row= rowSum.size();
        int col= colSum.size();
        vector<vector<int>>ans(row, vector<int>(col, 0));
        
        int i=0, j=0;
        while(i<row && j<col){
            ans[i][j] = min(rowSum[i], colSum[j]);
            
             rowSum[i]-= ans[i][j];
             colSum[j]-= ans[i][j];
           
            if(rowSum[i]==0) i++;
            if(colSum[j]==0) j++;
           
        }
        return ans;
    }
};