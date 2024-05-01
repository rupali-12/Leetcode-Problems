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
         reverse(word.begin(), word.begin()+firstIndex+1);
        return word;
    }
};