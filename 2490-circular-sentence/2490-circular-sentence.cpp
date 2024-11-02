class Solution {
public:
    bool isCircularSentence(string sentence) {
        bool ans= true;
        int n= sentence.length();
        if(sentence[0]!=sentence[n-1]) return false;
        
        for(int i=0; i<n; i++){
            if(sentence[i]==' ' && (sentence[i-1]!=sentence[i+1])){
                ans= false;
                return ans;
            }
        }
        return ans;
    }
};