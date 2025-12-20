class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
    
    // //  Approach-1 Brute Force 
    //     int count=0;
    //     int n=strs.size();
    //     int len = strs[0].length();
    //     for(int i=0; i<len; i++){
    //         string temp="";
    //        for(int curr=0; curr<n; curr++){
    //           temp+= strs[curr][i];   // current string ka ith char
    //        }
    //     //    now we have ith char of every string
    //     string withoutSort= temp;
    //     sort(temp.begin(), temp.end());
    //     if(temp!=withoutSort){   // those which are not sorted already
    //         count++;
    //     }
    //     }
    //     return count;

    // Approach 2: Optimize approach 
    int row = strs.size();
    int col = strs[0].length();
    int count=0;
    for(int c=0; c<col; c++){
        for(int r=1; r<row; r++){
            if(strs[r][c] < strs[r-1][c]){
                count++;
                break;
            }
        }
    }
    return count;
    }
};