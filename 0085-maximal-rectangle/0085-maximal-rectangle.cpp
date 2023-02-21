class Solution {
     private:
  vector<int>nextSmallerElements(int *M, int n){
        vector<int>ans(n);
        stack<int>s;
        s.push(-1);
        for(int i=n-1; i>=0; i--){
            while(s.top()!=-1 && M[s.top()]>=M[i]){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int>prevSmallerElements(int *M, int n){
        vector<int>ans(n);
        stack<int>s;
        s.push(-1);
        for(int i=0; i<n; i++){
            while(s.top()!=-1 && M[s.top()]>=M[i]){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    int largestArea(int *M, int n){
         vector<int>next(n);
         next = nextSmallerElements(M, n);
         
          vector<int>prev(n);
         prev = prevSmallerElements(M, n);
         int area=INT_MIN;
         for(int i=0; i<n; i++){
             int length =M[i];
             if(next[i]==-1){
                 next[i]=n;
           }
             int width = next[i]-prev[i]-1;
            int newArea= length *width;
             area =max(area, newArea);
         }
         return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        int M[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='0'){
                    M[i][j]=0;
                }
                else{
                    M[i][j]=1;
                }
            }
        }
          // compute area for first row 
        int area = largestArea(M[0],m);
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                // update row >>
                if(M[i][j]!=0){
                    M[i][j]= M[i][j]+ M[i-1][j];
                }
                else{
                    M[i][j]=0;
                }
            }
            int currArea = largestArea(M[i], m);
            area =max(area, currArea);
        }
        
        return area;
    }
};