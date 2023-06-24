class Solution {
public:
    int numberOfMatches(int n) {
        int matches=0;
        int advanceTeams=0;
        int totalMatches=0;
        while(n!=1){
            if(n%2==0){
                // case of even 
                 matches = n/2;
                advanceTeams = matches;
                
            }
            else{
                // case of odd 
                matches = (n-1)/2;
                advanceTeams = matches+1;
            }
            n = advanceTeams;
            totalMatches+= matches;
        }
        return totalMatches;
    }
};