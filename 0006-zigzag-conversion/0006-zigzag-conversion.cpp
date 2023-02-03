class Solution {
public:
    string convert(string s, int numRows) {
int  j=0, move=-1;
        string ans;
            if(numRows<2) return s;
        vector<string>temp(numRows, "");
        
        for(int i=0; i<s.length(); i++){
            if(j== numRows-1 || j==0){
                move*=-1;
            }
            temp[j]+= s[i];
            if(move==1) j++;
            else j--;
        }
        for(auto &it:temp){
            ans += it;
        }
        return ans;
    }
};