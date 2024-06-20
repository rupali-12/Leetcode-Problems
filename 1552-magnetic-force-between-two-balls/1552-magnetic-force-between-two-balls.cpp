class Solution {
public:
    bool isPossible(vector<int>&position, int midForce, int m){
        int count=1;
        int prev= position[0];
        
        for(int i=1; i<position.size(); i++){
            int curr= position[i];
            if((curr-prev)>=midForce){
                count++;
                prev= curr;
            }
            
            if(count==m) break;
        }
        return count==m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n= position.size();
        sort(position.begin(), position.end());
        int minForce=1, maxForce = position[n-1]-position[0];
        int ans;
        
        while(minForce<=maxForce){
            int midForce = minForce + (maxForce-minForce)/2;
            
            if(isPossible(position, midForce, m)){
                ans = midForce;
                minForce = midForce+1;
            }
            else{
                maxForce = midForce-1;
            }
        }
        return ans;
    }
};