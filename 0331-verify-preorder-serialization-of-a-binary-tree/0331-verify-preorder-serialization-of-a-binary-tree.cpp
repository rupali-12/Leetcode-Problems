class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string curr;
        int slots=1;  // 1 space for root 
        while(getline(ss, curr, ',')){
            if(slots<=0) return false;
            if(curr=="#"){
                slots-=1;
            }
            else{
                slots+=1;
            }
        }
        return slots==0;
    }
};