class Solution {
public:
    int minInsertions(string s) {
        int ans=0, need=0;
        for(int i=0;i<s.length(); i++){
            if(s[i]=='('){
                need+=2;

                // if need becomes odd then it means we need 1 closing
                if(need%2 ==1){
                    ans++;
                    need--;
                }
            }
            else{
                need--;
                // if need becomes neg then we need 1 open and needalso becomes 1 as 1 closing will also req
                if(need < 0){
                    ans++;
                    need=1;
                }
            }
        }
        return ans+need;
    }
};