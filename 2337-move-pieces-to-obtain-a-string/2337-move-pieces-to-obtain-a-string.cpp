class Solution {
public:
    
    bool solve(string &start, string &target, unordered_map<string, bool>&mp){
        if(start== target) return true;
        
        // Memoization using map
        if(mp.count(start)){
            return mp[start];
        }
        
        for(int i=0; i<start.length(); i++){
            if(start[i]=='L' && i>0 && start[i-1]=='_'){
                swap(start[i-1], start[i]);
                if(solve(start, target, mp)){
                    return true;
                }
                swap(start[i-1], start[i]);
            }
            else  if(start[i]=='R' && i<start.length() && start[i+1]=='_'){
                swap(start[i+1], start[i]);
                if(solve(start, target, mp)){
                    return true;
                }
                swap(start[i+1], start[i]);
            }
        }
        return mp[start]=false;
    }
    bool canChange(string start, string target) {
        
        // // Approach-1: Brute force 
        // unordered_map<string, bool>mp;
        // return solve(start, target, mp);
        
        // Approach-2: Optimized 
        int n= start.length(), i=0, j=0;
        
        while(i<n || j<n){
            while(i<n && start[i]=='_'){
                i++;
            }
           while(j<n && target[j]=='_'){
               j++;
           }
            
            if(start[i]!= target[j]) return false;
            
            if(i==n || j==n){
                return i==n && j==n;
            }
            
            if(start[i]=='L' && i<j) return false;
            if(start[i]=='R' && i>j) return false;
            
            i++;
            j++;
        }
        return true;
    }
};