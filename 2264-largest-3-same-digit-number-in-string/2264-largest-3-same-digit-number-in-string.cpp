class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="", str="";
        int i=0, j=1, count=1;
        str+= num[0];
        while(i<j && j<num.length()){
            if(num[i]==num[j]){
                str+= num[j];
                count++;
                if(count==3){
                    if(ans!=""){
                        // if((str[0]-'0')>(ans[0]-'0')){
                        if(str>ans){
                        ans= str;
                    }
                    }
                    else{
                        ans= str;
                    }
                    count=0;
                    str="";
                }
            }
            else{
                i=j;
                count=1;
                str= num[j];
            }
            j++;
        }
        return ans;
    }
};