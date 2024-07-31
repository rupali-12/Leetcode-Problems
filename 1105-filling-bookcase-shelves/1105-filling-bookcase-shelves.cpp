class Solution {
public:
    int n;
    int width;
    int dp[1001][1001];
    int solve(vector<vector<int>>&books, int i, int remainW, int maxHeight){
        if(i==n){
            return maxHeight;
        }
        if(dp[i][remainW]!=-1){
            return dp[i][remainW];
        }
        
        int bookW= books[i][0];
        int bookH= books[i][1];
        
        // keep 
        int keep= INT_MAX;
        if(bookW <= remainW){  // lets keep in same shelf
            keep= solve(books, i+1, remainW-bookW, max(maxHeight, bookH));
        }
        
        // skip   //and put in next shelf
        int skip = maxHeight + solve(books, i+1, width - bookW, bookH);
        return dp[i][remainW] = min(keep, skip);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n= books.size();
        width= shelfWidth;
        memset(dp, -1, sizeof(dp));
        
        int remainW= shelfWidth;
        return solve(books, 0, remainW, 0);
    }
};