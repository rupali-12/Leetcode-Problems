class Solution {
public:
    int compress(vector<char>& chars) {
       
        int i=0;
        int index=0;
        int n= chars.size();
       while(i<n){
           int j= i+1;
           while(j<n && chars[i]==chars[j]){
               j++;
           }
           
           // here reaches , when the complete array is traversed or a new character is encountered 
           chars[index++]= chars[i];
           int count = j-i;
            if(count>1){
             // convert counting into single digit
                string s = to_string(count);
                for(char ch: s){
                    chars[index++]= ch;
                }
            }
           // moving to next character 
           i=j;
       }
        return index;
    }
};