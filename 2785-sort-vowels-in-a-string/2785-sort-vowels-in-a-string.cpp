class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char, char>mp;
        for(auto ch: "aeiouAEIOU"){
            mp[ch]= ch;
        }
        
        string vowels="";
        for(auto &ch: s){
            if(mp.find(ch)!=mp.end()){
                vowels+= ch;
            }
        }
        
        sort(vowels.begin(), vowels.end());
        
        int index=0;
        for(auto &ch: s){
            if(mp.find(ch)!=mp.end()){
                ch = vowels[index++];
            }
        }
        return s;
    }
};