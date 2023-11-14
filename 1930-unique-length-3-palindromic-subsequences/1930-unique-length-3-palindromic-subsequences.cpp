class Solution {
public:
    int countPalindromicSubsequence(string s) {
      unordered_set<char>letters;
        int result=0;
        for(int i=0; i<s.length(); i++){
            letters.insert(s[i]);
        }
        
        for(auto letter: letters){
//             letter = 'a'
            int firstIdx = -1;
            int lastIdx = -1;
            for(int i=0; i<s.length(); i++){
                if(s[i]==letter){
                    if(firstIdx==-1){
                        firstIdx=i;
                    }
                    lastIdx= i;
                }
            }
            
            unordered_set<char>st;
            for(int middleIdx= firstIdx+1; middleIdx<lastIdx; middleIdx++){
                st.insert(s[middleIdx]);
            }
            result+= st.size();
        }
        return result;
    }
};