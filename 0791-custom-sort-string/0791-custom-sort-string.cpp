class Solution {
public:
    string customSortString(string order, string s) {
       string s1="", s2="";
        vector<int>count(26, 0);
        
        // store count of order 
        for(int i=0; i<order.size(); i++){
            count[order[i]-'a']++;
        }
        for(int i=0; i<s.length(); i++){
           if(count[s[i]-'a']==0){  // present in s but not in order
               s2+= s[i];
           }
           else{
                count[s[i]-'a']++;
           }
        }
        
        for(int i=0; i<order.length(); i++){
            while(count[order[i]-'a']>1){
                s1+= order[i];
                count[order[i]-'a']--;
            }
        }
        return s1+s2; 
    }
};