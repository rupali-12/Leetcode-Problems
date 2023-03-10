class Solution {
public:
// vector<int>add(vector<int>& num, vector<int>& vec2){
//     vector<int>res;
//     if(num.size()<vec2.size()){
//         reverse(num.begin(), num.end());
//         while(num.size()<vec2.size()){
//             num.push_back(0);
//         }
//          reverse(num.begin(), num.end());
//     }
//     else{
//      reverse(vec2.begin(), vec2.end());
//         while(num.size()>vec2.size()){
//             vec2.push_back(0);
//         }
//      reverse(vec2.begin(), vec2.end());
//     }
//     int j= num.size()-1, carry=0;
//     while(j>=0){
//      int sum = carry + num[j] +vec2[j];
//         int digit= sum%10;
//         res.push_back(digit);
//         carry = sum/10;
//         j--;
//     }
//     if(carry!=0){
//         res.push_back(carry);
//     }
//     reverse(res.begin(), res.end());
//     return res;
// }
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        // Approach-1>>
        // vector<int> ans;
        // vector<int> vec2;
        // while(k>0){
        //     int rem= k%10;
        //     vec2.push_back(rem);
        //     k/=10;
        // }
        // reverse(vec2.begin(), vec2.end());
        // ans =add(num, vec2);
        
        
        // **************************************************************
        // Approach-2>>>>
        int carry=0;
        int j= num.size()-1;
        while(j>=0){
            int sum =num[j]+carry + k%10;
            k/=10;
            
            num[j--]= sum%10;
            carry= sum/10;
        }
        while(k>0){
            int sum =  carry + k%10;
            k/=10;
            num.insert(num.begin(), sum%10);
            carry =sum/10;
        }
        if(carry>0){
            num.insert(num.begin(), carry);
        }
        return num;
    }
};