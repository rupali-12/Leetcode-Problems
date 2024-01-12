class Solution {
public:
    bool halvesAreAlike(string s) {
        int firstVowel=0, secondVowel=0;
        int i=0, j= s.length()-1;
        set<char>vowels{'a','e','i','o','u','A','E','I','O','U'};
        
        while(i<j){
            if(vowels.find(s[i])!=vowels.end()){
                firstVowel++;
            }
            if(vowels.find(s[j])!=vowels.end()){
                secondVowel++;
            }
            i++; j--;
        }
        return firstVowel==secondVowel ? true:false;
    }
};