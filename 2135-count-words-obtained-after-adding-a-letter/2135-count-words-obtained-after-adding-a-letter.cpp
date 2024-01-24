class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string>s;
        for(int i=0; i<startWords.size(); i++){
            sort(startWords[i].begin(), startWords[i].end());
            s.insert(startWords[i]);
        }
        
        int ans=0;
        for(int i=0; i<targetWords.size(); i++){
            bool flag=false;
            string current = targetWords[i];
            sort(current.begin(), current.end());
            
            // it give string rom index 0 to length i and from index i+1 to end 
            // it check by removing each character whether remaining string present in startWords or not 
           for(int j=0; j<current.length(); j++){
                string search = current.substr(0, j) + current.substr(j+1);
                  if(s.find(search)!=s.end()){
                   flag=true;
                    break;
              }
           }
              if(flag) ans++;
        }
        return ans;
    }
};