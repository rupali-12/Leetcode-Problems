class Solution {
public:
    string convert(string s, int numRows) {
// int  j=0, move=-1;
//         string ans;
//             if(numRows<2) return s;
//         vector<string>temp(numRows, "");
        
//         for(int i=0; i<s.length(); i++){
//             if(j== numRows-1 || j==0){
//                 move*=-1;
//             }
//             temp[j]+= s[i];
//             if(move==1) j++;
//             else j--;
//         }
//         for(auto &it:temp){
//             ans += it;
//         }
//         return ans;
        
        vector<string>temp(numRows);
        if(numRows==1){
            return s;
        }
        
        int i=0;
        bool flag=false;
       for(auto ch: s){
           temp[i]+= ch;
            if(i==0 || i==numRows-1){
            flag= !flag;
        }
           if(flag){
               i+=1;
           }
           else{
               i-= 1;
           }
       }
        
        string ans="";
        for(auto ch: temp){
            ans+= ch;
        }
        return ans;
    }
};