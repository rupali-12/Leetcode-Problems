class Solution {
public:
    int minFlips(int a, int b, int c) {
//         int count =0;
//         while(a!=0 || b!=0 || c!=0){
//             int lsba = (a&1);
//             int lsbb = (b&1);
//             int lsbc = (c&1);
//             if(lsba==lsbb){    // 00  11
//                 if(lsbc==1){
//                     if(lsba==0) count+=1;
//                 }
//                 else{    //lsbc=0
//                     if(lsba==1) count+=2;
//                 }
//             }
//             else{         // 10   01
//                 if(lsbc==0){
//                     count+=1;
//                 }
//             }
//             a= a>>1;
//             b= b>>1;
//             c= c>>1;
//         }
        
//         return count;
        
        // Second way 
        int count=0;
        while(a || b || c){
            if((c&1)==1){
                count+= ((a&1)==0) && ((b&1)==0);
            }
            else{
                count+= (a&1) + (b&1);
            }
            a>>=1; b>>=1; c>>=1;
        }
        return count;
    }
};