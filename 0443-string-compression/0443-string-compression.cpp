// class Solution {
// public:
//     int compress(vector<char>& chars) {
       
//         int i=0;
//         int index=0;
//         int n= chars.size();
//        while(i<n){
//            int j= i+1;
//            while(j<n && chars[i]==chars[j]){
//                j++;
//            }
           
//            // here reaches , when the complete array is traversed or a new character is encountered 
//            chars[index++]= chars[i];
//            int count = j-i;
//             if(count>1){
//              // convert counting into single digit
//                 string s = to_string(count);
//                 for(char ch: s){
//                     chars[index++]= ch;
//                 }
//             }
//            // moving to next character 
//            i=j;
//        }
//         return index;
//     }
// };



// *********************************************************************************
class Solution {
public:
    int compress(vector<char>& chars) {
       
        string temp;
        string ans="";
        
        for(int i=0; i<chars.size(); i++){
            if(temp.empty()){
                temp.push_back(chars[i]);
                ans+=chars[i];
            }
            else if(temp.back()!=chars[i]){
                if(temp.length()>1){
                    ans+= to_string(temp.length());
                }
                temp="";
                i--;
            }
            else{
                temp.push_back(chars[i]);
            }
        }
        if(temp.length()>1){
          ans+= to_string(temp.length());
        }
        int i=0;
        for(; i<ans.length(); i++){
            chars[i]=ans[i];
        }
      chars.erase(chars.begin()+i, chars.end());
        return chars.size();
    }
};