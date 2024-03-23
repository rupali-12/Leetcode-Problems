class Solution {
public:
    int takeCharacters(string s, int k) {
        int n= s.length();
        int ans=n;
        int countA=0, countB=0, countC=0;
        
        for(int i=0; i<n; i++){
            if(s[i]=='a') countA++;
            if(s[i]=='b') countB++;
            if(s[i]=='c') countC++;
        }
        
        if(countA<k || countB<k || countC<k) return -1;
        
        int left=0, right=0;
        while(right<n){
            if(s[right]=='a') countA--;
            if(s[right]=='b') countB--;
            if(s[right]=='c') countC--;
            
            // shrink if condition fails 
            if(countA<k || countB<k || countC<k){
                if(s[left]=='a') countA++;
                if(s[left]=='b') countB++;
                if(s[left]=='c') countC++;
                left++;
            }
            ans= min(ans, n-(right-left+1));
            right++;
        }
        return ans;
    }
};