class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        int n= words.size();
        for(char c = 'a'; c<='z'; c++){
            string temp(1, c);
            int minCount=INT_MAX;
            for(auto word: words){
                int count=0;
                for(char ch: word){
                    if(ch==c){
                        count++;
                    }
                }
                minCount= min(minCount, count);
            }
            
            for(int i=0; i<minCount; i++){
                ans.push_back(temp);
            }
        }
        return ans;
    }
};