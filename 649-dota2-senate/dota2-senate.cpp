class Solution {
public:
bool removalSenate(string &senate, char ch, int idx){
    bool CheckRemovalLeftSide=false;
    while(true){
        if(idx==0){
            CheckRemovalLeftSide =true;
        }

        if(senate[idx]==ch){
            senate.erase(begin(senate)+idx);  //shift
            break;
        }
        idx= (idx+1)%senate.length(); 
    }
    return CheckRemovalLeftSide;
}
    string predictPartyVictory(string senate) {
        int R_count = count(begin(senate), end(senate), 'R');
        int D_count = senate.length() - R_count;
        int idx=0;

        while(R_count>0 && D_count>0){
           if(senate[idx]=='R'){
           bool CheckRemovalLeftSide = removalSenate(senate, 'D', (idx+1)%senate.length());
           D_count--;
            if(CheckRemovalLeftSide){
                idx--;
            }
           }
           else{
           bool CheckRemovalLeftSide = removalSenate(senate, 'R', (idx+1)%senate.length());
           R_count--;
            if(CheckRemovalLeftSide){
                idx--;
            }
           }
           idx= (idx+1)%senate.length();  // cannot use n as senate length decreased after removal operation
        }
        return R_count==0 ? "Dire": "Radiant";
    }
};