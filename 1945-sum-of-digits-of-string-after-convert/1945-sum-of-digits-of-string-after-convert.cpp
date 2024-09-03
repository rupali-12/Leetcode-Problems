class Solution {
public:
    int getLucky(string s, int k) {
        long long num=0;
        for(int i=s.length()-1; i>=0; i--){
           int n = s[i]- 'a' + 1;
            num+= n<10? n: (n%10 + n/10);
        }
        
        while(k>1){
            int temp= num;
            num=0;
            while(temp!=0){
                num+= temp%10;
                temp/=10;
            }
            k--;
        }
        return num;
    }
};