class Solution {
public:
    bool checkOnesSegment(string s) {
        // // Approach -1 
        // int count=0;   // count of contigous count of 1's
        // int i=0;
        // while(i<s.length()){
        //     if(s[i]=='1'){
        //         count++;
        //         while(i<s.length() && s[i]=='1'){
        //             i++;
        //         }
        //     }
        //     else{
        //         i++;
        //     }

        //     if(count>1) return false;
        // }
        // return true;

        // Approach 2: find pattern "01" , if not found then true
        return s.find("01")==string::npos;   // means not found, and when we not found then only one set is present
        
    }
};