class Solution {
public:
    int maxOperations(string s) {
        int ans=0;
        int ones=0;
        int n=s.length();
        bool flag=false; // handle if current is 1 then true else false for 0
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                ones++;
                flag= true;
            }
            if(s[i]=='0' && flag){  // current is 0 and flag is there
                ans+= ones;
                flag = false; // flag set to false as current is 0
            }
        }
        return ans;
    }
};
