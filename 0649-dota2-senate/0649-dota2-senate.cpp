class Solution {
public:
    bool removeSenate(string &senate, char ch, int idx){
        bool chkFromLeft= false;
        while(true){
            if(idx==0) chkFromLeft=true;
            if(senate[idx]==ch){
                senate.erase(begin(senate)+idx);
                break;
            }
            idx= (idx+1)%senate.length();
        }
        return chkFromLeft;
    }
    string predictPartyVictory(string senate) {
        // Approach-1: Brute force 
        // count D and R
        int count_R = count(begin(senate), end(senate), 'R');
        int count_D = count(begin(senate), end(senate), 'D');
        
        int idx=0;
       while(count_R>0 && count_D>0){
            // if 'R' delete someone 'D' at right 
           if(senate[idx]=='R'){
            bool checkRemovalFromLeft = removeSenate(senate,'D', (idx+1)%(senate.length()));
               count_D--;
               if(checkRemovalFromLeft){
                   idx--;
               }
           }
           else{
            // if 'D' delete someone 'R' at right 
               bool checkRemovalFromLeft = removeSenate(senate, 'R', (idx+1)%(senate.length()));
               count_R--;
               if(checkRemovalFromLeft){
                   idx--;
               }
           }
           idx= (idx+1)%senate.length();
       }
        return count_R==0?"Dire":"Radiant";
     }
};