class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // vector<int>ans;
        // int carry=0;
        // for(int i=digits.size()-1; i>=0; i--){
        //     if(digits[i]<9){
        //         if(carry){
        //           digits[i]+=carry;
        //             // carry=0;
        //         }
        //          if(i==digits.size()-1){
        //               digits[i]+=1;
        //          }
        //         return digits;
        //     }
        //     else{
        //         carry=1;
        //         digits[i]=0;
        //     }
        // }
        // if(carry){
        //     ans.push_back(carry);
        // }
        // for(int i=0; i<digits.size(); i++){
        //     ans.push_back(digits[i]);
        // }
        // return ans;
        
        
        // Approach-2 By forming Number>>
for(int i=digits.size()-1; i>=0; i--){
    if(digits[i]<9){
        digits[i]++;
        return digits;
    }
    else{
        digits[i]=0;
    }
}
        digits.push_back(0);
        digits[0]=1;
        return digits;
    }
};