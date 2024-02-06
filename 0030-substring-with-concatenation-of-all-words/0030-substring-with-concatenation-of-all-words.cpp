class Solution {
public:
//     // Approach-1: Brute force give TLE  
//     vector<int> findSubstring(string s, vector<string>& words) {
//         vector<int>ans;
//         int n = words.size();
//         int m = words[0].length();
//         if(s.size()<n*m) return ans;
        
//         for(int i=0 ; i<=s.size()-m*n; i++){
//             unordered_map<string, int>mp;
//             // store count of each string of words in map
//             for(int k=0; k<n; k++){
//                 mp[words[k]]++;
//             }
            
//             int j;
//             // check words vector for every index i 
//             for(j =0; j<n; j++){
//                 string str = s.substr(i+j*m, m);   // (0, 3) => from index=0, length =3
//               // if count of str in map =0 then break to avoid further check 
//                 if(mp.count(str)==0){
//                     break;
//                 }
//                 else{
//                     // if count of str in map i not equal to 0 then reduce else break as may be same string will be extra 
//                     if(mp[str]!=0){
//                         mp[str]--;
//                     }
//                     else{
//                         break;
//                     }
//                 }
//             }
//             // after processsing whole words vector check if j== n means inner loop runs equlal to words.size means all words  find
//             if(j==n){
//                 ans.push_back(i);
//             }
//         }
        
//         return ans;
//     }
    
    
    // ******************************************************************
     // Approach-2: Sliding Window  
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        int n = words.size();
        int m = words[0].length();
        if(s.size()<n*m) return ans;
        unordered_map<string, int>mp1;
        for(int i=0; i<n; i++){
            mp1[words[i]]++;
        }
        
        for(int i=0;i<m; i++){  // till m because j move to s.size()-m so may be matching string start in limit 0 to <m
            unordered_map<string, int>mp2;
            int left= i;
            for(int j=i; j<=s.size()-m; j+= m){
                string str = s.substr(j, m);
                if(mp1.find(str)!=mp1.end()){
                    mp2[str]++;
                    
                    while(mp2[str]>mp1[str]){
                        mp2[s.substr(left, m)]--;
                        left+= m;  
                    }
                    
                    if((j-left+m)==m*n){
                        ans.push_back(left);
                        mp2[s.substr(left, m)]--;
                        left+= m;
                    }
                }
                else{
                    // clear mp2 and move j 
                    mp2.clear();
                    left = j+m;
                }
            }
        }
      
        
        return ans;
    }
};