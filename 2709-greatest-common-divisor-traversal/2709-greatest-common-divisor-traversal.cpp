class Solution {
public:
    unordered_map<int, vector<int>>index2Prime;
    unordered_map<int, vector<int>>prime2Index;
    
    void dfs(int index,  vector<int>&visitedIndex, unordered_map<int, bool>&visitedPrime){
        if(visitedIndex[index]==true) return;
        visitedIndex[index]=true;
        
        // All elements that have common prime factors will be adjacent 
        // so loop through all prime factors of this number, then loop through all elements that have common prime factors in common 
        
        for(auto &prime: index2Prime[index]){
            // already visited 
            if(visitedPrime[prime]==true) continue;
            
            // mark 
            visitedPrime[prime]=true;
            
            // loop through all elements that have this prime factor in commmon 
            for(auto &index1: prime2Index[prime]){
                if(visitedIndex[index1]==true) continue;
                dfs(index1, visitedIndex, visitedPrime);
            }
        }
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        int n= nums.size();
        // Find all prime factors and create two mappings 
        for(int i=0; i<n; i++){
            int temp= nums[i];
            for(int j=2; j*j<=nums[i]; j++){
                if(temp%j==0){
                   index2Prime[i].push_back(j);
                    prime2Index[j].push_back(i);
                    while(temp%j==0){
                        temp/=j;
                    }
                }
            }
            // To handle case, when prime factor>square root
            if(temp>1){
                index2Prime[i].push_back(temp);
                prime2Index[temp].push_back(i);
            }
        }
        
        // Run dfs from 0th index 
        vector<int>visitedIndex(n, 0);
       unordered_map<int, bool>visitedPrime;
        dfs(0, visitedIndex, visitedPrime);
        
        // if not all elements reached then return false(means for disconnected components return false)
        for(int i=0; i<visitedIndex.size(); i++){
            if(visitedIndex[i]==false){
                return false;
            }
        }
        return true;
    }
};