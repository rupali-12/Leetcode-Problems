class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int p= pattern.length(), n= s.length();
        
        // Approach-1: TC= O(p*n)
        
        stringstream ss(s);
        string word;
        int count=0;
        while(ss >> word){
            count++;
        }
        if(count!= p) return false;
        
       map<char, string>mp;
        int idx=0;
        for(int i=0; i<p; i++){
            char ch =pattern[i];
            string temp="";
            while(idx<n && s[idx]!=' '){
                temp+= s[idx];
                idx++;
            }
            idx++;  //   increase for white space
  
            // if present in map 
            if(mp.find(ch)!= mp.end()){
                if(mp[ch]!=temp)return false;
            }
            else{
                // check if temp is present for multiple key or not is it then fale 
                for(auto &m: mp){
                    if(m.second==temp) return false;
                }
            }
            
            mp[ch]= temp;
            temp="";
        }
        return true;
    }
};