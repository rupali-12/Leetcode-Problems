class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
       int rightKnownSum =0, leftKnownSum=0;
       int leftQnMarkCount=0, rightQnMarkCount=0;
       for(int i=0; i<n; i++){
        if(num[i]=='?'){
          if(i<n/2){
            leftQnMarkCount++;
          }
          else{
            rightQnMarkCount++;
          }
        }
        else{
          if(i<n/2){
            leftKnownSum+= num[i]-'0';
          }
          else{
            rightKnownSum+= num[i]-'0';
          }
        }
       }

       int totalQnMarkCount = leftQnMarkCount + rightQnMarkCount;
       if(totalQnMarkCount %2 ==1){   // Odd - Alice always win
        return true;
       }

       int left = 2*leftKnownSum + 9*leftQnMarkCount;
       int right = 2*rightKnownSum + 9*rightQnMarkCount;
       if(left == right) return false;
       return true;
    }
};