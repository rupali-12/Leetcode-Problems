class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int>mp;
        for(int i=0; i<order.length(); i++){
            mp[order[i]]=i;
        }

        for(int i=0; i<words.size()-1; i++){
            for(int j=0; j<words[i].length(); j++){

                // case batman bat
                if(j >= words[i+1].length()){
                    return false;
                }

                if(words[i][j] != words[i+1][j]){
                    int currLetterIdx = mp[words[i][j]];
                    int nextLetterIdx = mp[words[i+1][j]];
                    if(nextLetterIdx < currLetterIdx){
                        return false;
                    }
                    else{
                    break;
                }
                }
            }
        }
        return true;
    }
};