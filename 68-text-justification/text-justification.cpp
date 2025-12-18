class Solution {
public:
int MAX_WIDTH;
    string findLine(int i, int j, int eachGaddheSpace, int extraGaddheSpace, vector<string>words){
         string line;

         for(int k=i; k<j; k++){
            line+= words[k];
            
            if(k==j-1){   // last word of my line
                continue;
            }
            for(int z=1; z<= eachGaddheSpace; z++){
                line+= " ";
            }
            if(extraGaddheSpace>0){
                line+= " ";
                extraGaddheSpace--;
            }
         }

         while(line.length() < MAX_WIDTH){
            line+= " ";
         }
         return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>result;
        int n = words.size();
        MAX_WIDTH = maxWidth;
        int i=0;

        while(i<n){
        int lettersCount =words[i].length();
        int j=i+1;
        int gaddhe = 0;

        while(j<n && (words[j].length() + 1 + gaddhe + lettersCount) <= maxWidth){
            lettersCount+= words[j].length();
            gaddhe+= 1;
            j++;
        }

        int remainingGaddheSpaces = maxWidth - lettersCount;
        int eachGaddheSpace = gaddhe==0? 0: remainingGaddheSpaces/gaddhe;
        int extraGaddheSpace = gaddhe==0? 0: remainingGaddheSpaces%gaddhe;

        if(j==n){   // last line - left justification
          eachGaddheSpace =1;
          extraGaddheSpace =0;
        }
            
        result.push_back(findLine(i, j, eachGaddheSpace, extraGaddheSpace, words));

        i = j;
        }

        return result;
    }
};