class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        // Approach 1: Brute force
        if(encodedText == "") return "";
        int cols = encodedText.length()/rows;
        vector<vector<char>>mat(rows, vector<char>(cols, ' '));
        int cnt = 0;
        // fill matrix 
       for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            mat[i][j] = encodedText[cnt++];
        }
       }

       string ans="";
    //    process matrix 
    for(int col =0; col<cols; col++){
        int i=0;
        int j=col;
        while(i<rows && j<cols){
            ans+=mat[i][j];
            i++; j++;
        }
    }

    //   Remove trailing spaces
    while(ans.back() == ' '){
        ans.pop_back();
    }
      return ans;
    }
};