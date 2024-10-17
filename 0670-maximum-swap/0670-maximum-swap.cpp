class Solution {
public:
    int maximumSwap(int num) {
        string numStr= to_string(num);
        int n= numStr.size();
        
        // store last occurence of each character 
        vector<int>last(10, -1);
        for(int i=0; i<n; i++){
            last[numStr[i]-'0']= i;
        }
        
        for(int i=0; i<n; i++){
            // check if lasrger digit comes later 
            for(int d=9; d>(numStr[i]-'0'); d--){
                if(last[d]>i){
                    // swap
                    swap(numStr[i], numStr[last[d]]);
                    return stoi(numStr);
                }
            }
        }
        
        return num;   // return original if no swapping 
    }
};



