class Solution {
  
public:
    string addBinary(string a, string b) {
      string ans="";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        if(a.size()>b.size()){
            while(a.size()>b.size()){
                b.push_back('0');
            }
        }
        else if(b.size()>a.size()){
            while(b.size()>a.size()){
                a.push_back('0');
            }
        }
        
        int c=0;
        for(int i=0; i<a.size(); i++){
            if(a[i]=='0' && b[i]=='0' && c==0){
                ans+= '0';
                c=0;
            }
            else if(a[i]=='0' && b[i]=='0' && c==1){
                ans+= '1';
                c=0;
            }
            else if((a[i]=='1' && b[i]=='0' && c==0) || (a[i]=='0' && b[i]=='1' && c==0)){
                ans+= '1';
                c=0;
            }
             else if((a[i]=='1' && b[i]=='0' && c==1) || (a[i]=='0' && b[i]=='1' && c==1)){
                ans+= '0';
                c=1;
            }
             else if(a[i]=='1' && b[i]=='1' && c==0){
                ans+= '0';
                c=1;
            }
            else if(a[i]=='1' && b[i]=='1' && c==1){
                ans+= '1';
                c=1;
            }
        }
        if(c==1){
            ans+='1';
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};