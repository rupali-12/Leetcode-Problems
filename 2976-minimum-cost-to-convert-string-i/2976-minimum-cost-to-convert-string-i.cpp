class Solution {
public:
    void floydWarshal(vector<vector<long long>>&adjMatrix, vector<char>& original, vector<char>& changed, vector<int>& cost){
         for(int i=0; i<original.size(); i++){
             int s= original[i]-'a';
             int t= changed[i]-'a';
             
             adjMatrix[s][t] = min(adjMatrix[s][t], (long long)cost[i]);
         }    
        
        // check every possibility from i to j via k 
        for(int k=0; k<26; k++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    adjMatrix[i][j] = min(adjMatrix[i][j], (adjMatrix[i][k]+adjMatrix[k][j]));
                }
            }
        }
        return;
    }
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>adjMatrix(26, vector<long long>(26, INT_MAX));
        
        floydWarshal(adjMatrix, original, changed, cost);
        
        long long ans=0;
        
        for(int i=0; i<source.size(); i++){
            if(source[i]==target[i]) continue;
            
            if(adjMatrix[source[i]-'a'][target[i]-'a'] ==INT_MAX){
                return -1;
            }
            
            ans+= adjMatrix[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};