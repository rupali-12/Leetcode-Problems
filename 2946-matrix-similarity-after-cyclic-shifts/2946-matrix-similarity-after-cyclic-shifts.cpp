class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>>temp = mat;
      while(k--){
         for(int i=0; i<m; i++){
            int first = mat[i][0];
        //   for even row, shift left
           if(i%2==0){
             for(int j=0; j<n-1; j++){
               mat[i][j]= mat[i][j+1];
            }

            // Now fill end column position
            mat[i][n-1] = first;
           }
        else{
            int last = mat[i][n-1];
        //   for even row, shift right
             for(int j=n-1; j>0; j--){
               mat[i][j]= mat[i][j-1];
            }

            // Now fill first column position
            mat[i][0] = last;
           }
        }
      }
 
        return temp==mat;
    }
};

