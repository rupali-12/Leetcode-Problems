class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count =0;
        while(a!=0 || b!=0 || c!=0){
            int lsba = (a&1);
            int lsbb = (b&1);
            int lsbc = (c&1);
            if(lsba==lsbb){    // 00  11
                if(lsbc==1){
                    if(lsba==0) count+=1;
                }
                else{    //lsbc=0
                    if(lsba==1) count+=2;
                }
            }
            else{         // 10   01
                if(lsbc==0){
                    count+=1;
                }
            }
            a= a>>1;
            b= b>>1;
            c= c>>1;
        }
        
        return count;
    }
};