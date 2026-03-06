class Solution {
public:
    bool checkOnesSegment(string s) {
        int count=0;
        int i=0;
        while(i<s.length()){
            if(s[i]=='1'){
                count++;
                while(i<s.length() && s[i]=='1'){
                    i++;
                }
            }
            else{
                i++;
            }

            if(count>1) return false;
        }
        return true;
    }
};