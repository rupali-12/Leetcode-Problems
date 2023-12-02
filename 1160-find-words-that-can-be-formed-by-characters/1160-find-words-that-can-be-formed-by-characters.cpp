class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char, int>mp;
        for(auto a: chars){
            mp[a]++;
        }
        
        int ans=0;
        for(int i=0; i<words.size(); i++){
            string str=words[i];
            map<char, int>temp;
            for(int j=0; j<str.length(); j++){
                temp[str[j]]++;
            }
            
            // check if freq of each character in mp is greater than or equal than in temp 
            bool valid=true;
            for(auto &a: temp){
                if(mp[a.first]<a.second){
                    valid= false;
                    break;
                }
            }
            if(valid){
                ans+= str.length();
            }
        }
        return ans;
    }
};