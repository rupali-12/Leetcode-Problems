class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count=0;
        int n=strs.size();
        int len = strs[0].length();
        for(int i=0; i<len; i++){
            string temp="";
           for(int curr=0; curr<n; curr++){
              temp+= strs[curr][i];   // current string ka ith char
           }
        //    now we have ith char of every string
        string withoutSort= temp;
        sort(temp.begin(), temp.end());
        if(temp!=withoutSort){   // those which are not sorted already
            count++;
        }
        }
        return count;
    }
};