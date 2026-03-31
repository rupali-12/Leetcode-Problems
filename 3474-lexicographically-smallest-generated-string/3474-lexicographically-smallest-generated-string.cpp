class Solution {
public:
    bool isSame(string &word, string&str2, int i,int m){
        for(int j=0; j<m; j++){
          if(word[i]!=str2[j]){
            return false;
          }
          i++;
        }
        return true;
    }
    string generateString(string str1, string str2) {
        int n=str1.length(), m=str2.length();

        int N=n+m-1;
        string word(N, '$');
        vector<bool>canChange(N, false);

        // Process 'T'
        for(int i=0; i<n; i++){
            if(str1[i]=='T'){
                int i_ = i;
                for(int j=0; j<m; j++){
                    // if already set and not equal to str2[j] then return ""
                    if(word[i_]!='$' && word[i_]!= str2[j]){
                        return "";
                    }
                    word[i_] = str2[j];
                    i_++;
                }
            }
        }

        // Fill remaining spaces with 'a'
        for(int i=0; i<N; i++){
            if(word[i]=='$'){
                word[i]='a';
                canChange[i]=true; 
            }
        }

        // Process 'F'
        for(int i=0; i<n; i++){
            if(str1[i]=='F'){
                // check if in word from index i to length m is equal to str2 or now 
                // if same then we need to make it unequal
                if(isSame(word, str2, i, m)){
                    // traverse from right and change any a to b to make it unequal
                    bool isChange=false;
                    for(int k=i+m-1; k>=i; k--){
                       if(canChange[k]==true){
                        word[k]='b';
                        isChange=true;
                        break;
                       }
                    }
                    // if we not able to chnage then return ""
                    if(isChange==false){
                        return "";
                    }
                }
            }
        }
        return word;
    }
};