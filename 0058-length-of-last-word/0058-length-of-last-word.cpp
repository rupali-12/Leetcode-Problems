class Solution {
public:
    int lengthOfLastWord(string s) {
        // Aproach-1:
        int len=0;
        for(int i= s.length()-1; i>=0; i--){
           if(len!=0 && s[i]==' '){
               break;
           }   
            else if(s[i]!=' ')
                len++;
        }
        return len;
        
      //   Approach-2: 
      // int length=0;
      //   bool counting= false;
      //   for(int i= s.length()-1; i>=0; i--){
      //       if(s[i]!= ' '){
      //           counting = true;
      //           length++;
      //       }
      //       else if(counting){
      //           break;
      //       }
      //   }
      //   return length;
    }
};