class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string>words;
        string word="";
        
        // separate words from string 
        for(int i=0; i<s.size(); i++){
           if(s[i]!=' '){
               word+= s[i];
           }    
            else{
                words.push_back(word);
                word="";
            }
        }
        // insert last word 
        words.push_back(word);
        
        // find max length 
        int max_length=0;
        for(int i=0; i<words.size(); i++){
            max_length = max(max_length, (int)words[i].size());
        }
        
//         // fill answer vector
        vector<string>ans(max_length, "");
        
        for(int i=0; i<words.size(); i++){
            
            // fill every word with spaces until max_length
            int filler_len = max_length - (int)(words[i].length());
            for(int j=0; j<filler_len; j++){
                words[i]+= " ";
            }
        }
        

        
        // fill ans vector
        for(int i=0; i<max_length; i++){
            for(int j=0; j<words.size(); j++){
                ans[i]+= words[j][i];
            }
        }
        
        // remove right white spaces 
        for(int i=0; i<ans.size(); i++){
            int j= ans[i].size()-1;
            while(ans[i][j]==' '){
                ans[i].pop_back();
                j--;
            }
        }
        return ans;
        
        

    }
};