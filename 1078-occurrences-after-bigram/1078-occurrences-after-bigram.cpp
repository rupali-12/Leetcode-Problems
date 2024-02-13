class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string>ans;
        vector<string>str;
        string temp="";
        for(int i = 0; i < text.length(); i++){
            if(text[i] == ' '){
                str.push_back(temp);
                temp = "";
            }
            else {
                temp += text[i];
            }
        }
        // Push the last word
        str.push_back(temp);
        
        for(int i=0; i<str.size()-2; i++){
            if((str[i]==first) && (str[i+1]==second)){
                // third= str[i+2];
                ans.push_back(str[i+2]);
            }
        }
        return ans;
    }
};