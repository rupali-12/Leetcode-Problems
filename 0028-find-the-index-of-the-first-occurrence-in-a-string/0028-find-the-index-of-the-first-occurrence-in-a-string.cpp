class Solution {
public:
    int strStr(string haystack, string needle) {
        // Approach-1>>
//         int n = haystack.length();
//        vector<int>lps(needle.size(), 0);
//         for(int i=1; i<needle.size(); i++){
//             int j= lps[i-1];
//             while(j>0 && needle[j]!=needle[i]){
//                 j =lps[j-1];
//             }
//             if(needle[j]==needle[i]){
//                 j++;
//             }
//             lps[i]=j;
//         }
        
//         int i=0, j=0;
//         int ans=-1;
//         int m=needle.size();
//         while(i<n){
//             if(needle[j]==haystack[i]){
//                 i++; j++;
//             }
           
//             // if you match all characters and still inside haystack string mead j=m
//             if(j==m){
//                 ans = i-m;
//                 return ans;
//                 // j= lps[j-1];
//             }
            
//         else if(needle[j]!=haystack[i]){
//             if(j==0) {i++;}
//             else{
//             j= lps[j-1];
//             }   
//         }
//         }
//         return ans;
        
        // Approach-2> 
        if(needle.length()>haystack.length()){
            return -1;
        }
        for(int i=0; i< haystack.length()- needle.length()+1; i++){
            if(needle[0]==haystack[i]){
               string temp= haystack.substr(i, needle.length());
                if(temp==needle){
                    return i;
                }
            }
        }
        return -1;
        
        // // Approach-3> using built-in function
        // int i= haystack.find(needle);
        // return i;
    }
};