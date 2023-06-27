class Solution {
public:
    string maximumBinaryString(string binary) {
     int n= binary.size();
        if(n==1) return binary;
        
     int start=n+1;
        for(int i=0; i<n; i++){
            if(binary[i]=='0'){
                start=i;
                break;
            }
        }
        
        int zero=0;
        for(int i=0; i<n; i++){
            if(binary[i]=='0'){
               zero++;
            }
        }
        
        string ans(n, '1');
        if((zero +start-1)<n){
            ans[zero+start-1]='0';
        }
        return ans;
    }
};