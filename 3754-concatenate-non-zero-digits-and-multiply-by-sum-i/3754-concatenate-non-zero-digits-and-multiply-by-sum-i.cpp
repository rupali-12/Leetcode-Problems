class Solution {
public:
    long long sumAndMultiply(int n) {
        // if(n==0) return 0;
        // string str = to_string(n);
        // string s ="";
        // for(int i=0; i<str.length(); i++){
        //     if(str[i]!='0'){
        //         s+= str[i];
        //     }
        // }
        // long long sum=0;
        // for(auto ch :s){
        //     sum+= ch-'0';
        // }

        // long long ans = 0;
        // int num = stoi(s);
        // ans = num*sum;
        // return ans;

        // Approach-1:optimize
        if(n==0) return 0;
        long long num =0, sum=0, place=1;
        while(n>0){
            int digit = n%10;
            if(digit!=0){
                num+= digit*place;
                place*=10;
                sum+= digit;
            }
            n/=10;
        }
        return num*sum;
    }
};