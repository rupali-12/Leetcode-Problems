class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n= s.length(), ans=0;
        unordered_set<char>letters;
        for(int i=0; i<n; i++){
            letters.insert(s[i]);
        }

        for(auto letter: letters){
            int left_idx=-1;
            int right_idx=-1;
            
            // find left and right most index of letter 
            for(int i=0; i<n; i++){
               if(s[i]==letter){
                if(left_idx==-1){
                left_idx=i;
               }
               right_idx=i;
               }
            }

            unordered_set<char>btwchar;
            for(int mid=left_idx+1; mid<= right_idx-1; mid++){
                btwchar.insert(s[mid]);
            }
            ans+= btwchar.size();
        }
        return ans;
    }
};