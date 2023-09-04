class Solution {
public:
    int longestValidParentheses(string s) {
      int left=0,right=0;
        int n= s.length();
        int mx= 0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                left++;
            }
            else{
                right++;
            }
            
            // check left and right 
            if(left==right){
                mx= max(mx, left*2);
            }
             else if(left<right){
                    left=0;
                    right=0;
                }
        }
        
        // check for right
        left=0;
        right=0;
           for(int i=n-1; i>=0; i--){
            if(s[i]=='('){
                left++;
            }
            else{
                right++;
            }
            
            // check left and right 
            if(left==right){
                mx= max(mx, right*2);
            }
             else if(left>right){
                    left=0;
                    right=0;
                }
        }
            return mx;
    }
};