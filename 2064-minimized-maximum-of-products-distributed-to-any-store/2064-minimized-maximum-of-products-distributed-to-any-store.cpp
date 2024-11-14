class Solution {
public:
    int m;
    bool isPossibleAnswer(int x, vector<int>&quantities, int n){
        for(int i=0; i<m; i++){
            int product= quantities[i];
            n-= (product+x-1)/x;   // another way to write ceil   n-= (product+x-1)/x;
            // ceil function may give wrong integer so use this in place of ceil function
            if(n<0){
                return false;
            }
        }    
        return true;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        m= quantities.size();
        
        int ans=0;
        int l=1;
        int r = *max_element(begin(quantities), end(quantities));
        
        while(l<=r){
            int mid= l + (r-l)/2;
            
            if(isPossibleAnswer(mid, quantities, n)){
                ans= mid;
                r= mid-1;
            }
            else{
                // Not valid answer
                l= mid+1;
            }
        }
        return ans;
    }
};