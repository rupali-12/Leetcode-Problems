class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n= grid.size();

        vector<int>endZeros(n);
        // endZeros[i] = consecutive 0's from end of ith row
        for(int i=0; i<n; i++){
           int j=n-1;

           int count=0;
           while(j>=0 && grid[i][j]==0){
            count++;
            j--;
           }
           endZeros[i] = count;
        }

        int ans=0;
        for(int i=0; i<n; i++){
            int need= n-i-1;
            int j=i; // start from i, if ith itself has sufficient zeros then no need to check further

            while(j<n && endZeros[j]<need){
                j++;
            }

            if(j==n){   // nothing found
              return -1;
            }

            ans += j-i;

            // now swap from found index to index >i
            while(j>i){
                swap(endZeros[j], endZeros[j-1]);
                j--;
            }
        }
        return ans;
    }
};