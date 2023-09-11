class Solution {
public:
    bool solveRec(string s1, string s2){
         if(s1.compare(s2)==0){
            return true;
        }
        
        // if len<=1 // equal to consiered bcoz they are not equal as wel as per above                condition 
        if(s1.length()<=1){
            return false;
        }
        
        int n= s1.length();
        bool flag=false;    // we consider that are not scramble
        
        // not start with 0 as not child can be empty 
        for(int i=1; i<=n-1; i++){
            // case 1: if swap is done 
            // substr(startindex, length)
            bool swap = solveRec(s1.substr(0, i), s2.substr(n-i, i)) &&                               solveRec(s1.substr(i,n-i), s2.substr(0, n-i));
            
             // case 2: if swap is not done 
            bool notSwap = solveRec(s1.substr(0, i), s2.substr(0, i)) &&                               solveRec(s1.substr(i,n-i), s2.substr(i, n-i));
            
            if(swap || notSwap){
                flag= true;
                break;
            }
        }
        return flag;
    }
       bool solveMem(string s1, string s2, unordered_map<string, bool>&mp){
         if(s1.compare(s2)==0){
            return true;
        }
        
        // if len<=1 // equal to consiered bcoz they are not equal as wel as per above                condition 
        if(s1.length()<=1){
            return false;
        }
           
           // Make key as according to store result 
           string key= s1;
           key.push_back(' ');
           key.append(s2); 
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }
        int n= s1.length();
        bool flag=false;    // we consider that are not scramble
        
        // not start with 0 as not child can be empty 
        for(int i=1; i<=n-1; i++){
            // case 1: if swap is done 
            // substr(startindex, length)
            bool swap = solveMem(s1.substr(0, i), s2.substr(n-i, i), mp) &&                               solveMem(s1.substr(i,n-i), s2.substr(0, n-i), mp);
            
             // case 2: if swap is not done 
            bool notSwap = solveMem(s1.substr(0, i), s2.substr(0, i), mp) &&                               solveMem(s1.substr(i,n-i), s2.substr(i, n-i), mp);
            
            if(swap || notSwap){
                flag= true;
                break;
            }
        }
        return mp[key]= flag;
    }
    bool isScramble(string s1, string s2) {
       // // Approach-1: Recursion 
       //  return solveRec(s1, s2);
        
        // Approach-2: Memoization 
        unordered_map<string, bool>mp;
        return solveMem(s1, s2, mp);
    }
};