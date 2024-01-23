class Solution {
public:
    bool hasDuplicate(string &s1, string &s2){
        int arr[26]={0};
        
        for(char &ch: s1){
            // check case like "aa", "bb"
            if(arr[ch-'a']>0) return true;
            
            arr[ch-'a']++;
        }
        
        for(char &ch: s2){
            if(arr[ch-'a']>0){
                return true;
            }
        }
        return false;
    }
    int solve(vector<string>&arr, int i, string temp){
        if(i==arr.size()){
            return temp.size();
        }
       
        int include = 0, exclude = 0;
       // first pass arr[i] as in duplicate function we check for cases like aa, bb 
        if(hasDuplicate(arr[i], temp)){  // can exclude only
          exclude = solve(arr, i+1, temp);
        }
        else{    // can include as well as exclude
            exclude = solve(arr, i+1, temp);
            include = solve(arr, i+1, temp+arr[i]);
        }
        return max(include, exclude);
    }
    int maxLength(vector<string>& arr) {
     int n= arr.size();
       string temp="";
       
        return solve(arr, 0, temp);
    }
};