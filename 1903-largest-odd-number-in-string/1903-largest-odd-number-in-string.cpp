class Solution {
public:
    string largestOddNumber(string num) {
        string ans="", temp="";
        
        for(int i=0; i<num.length(); i++){
            int c = num[i]-'0';
            if(c%2!=0){
                ans+= num[i];
            }
            else{
                temp+= num[i];
                if((i!=num.length()-1) && (num[i+1]-'0')%2!=0){
                    ans+= temp;
                    temp="";
                }
            }
        }
        return ans;
    }
};