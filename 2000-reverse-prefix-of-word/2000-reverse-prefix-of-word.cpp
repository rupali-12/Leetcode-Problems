class Solution {
public:
    string reversePrefix(string word, char ch) {
        int firstIndex=-1;
        for(int i=0; i<word.length(); i++){
            if(word[i]==ch){
                firstIndex= i;
                break;
            }
        }
        if(firstIndex==-1) return word;
        string ans = word.substr(0, firstIndex+1);
        reverse(ans.begin(), ans.end());
        
        // merge remaining part 
        ans+= word.substr(firstIndex+1);
        return ans;
    }
};