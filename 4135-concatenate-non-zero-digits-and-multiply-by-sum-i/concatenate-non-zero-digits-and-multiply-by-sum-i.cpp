class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        string str = to_string(n);
        string s ="";
        for(int i=0; i<str.length(); i++){
            if(str[i]!='0'){
                s+= str[i];
            }
        }
        long long sum=0;
        for(auto ch :s){
            sum+= ch-'0';
        }

        long long ans = 0;
        int num = stoi(s);
        ans = num*sum;
        return ans;
    }
};