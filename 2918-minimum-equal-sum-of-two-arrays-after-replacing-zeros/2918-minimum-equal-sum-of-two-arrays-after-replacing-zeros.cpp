class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        
//         // Way-1: 
//         long long s1=0, s2=0, c1=0, c2=0;
//         for(int i=0; i<nums1.size(); i++){
//             s1+= nums1[i];
//             if(nums1[i]==0) c1++;
//         }
//          for(int i=0; i<nums2.size(); i++){
//             s2+= nums2[i];
//             if(nums2[i]==0) c2++;
//         }
        
//         if(c1==0 && c2==0){
//             if(s1!=s2) return -1;
//             else return s1;
//         }
//         else if(c1==0  && c2!=0){
//             if(s1<=s2) return -1;
//             else{
//                 if(c2>(s1-s2)) return -1;
//                 else return s1;
//             }
//         }
//          else if(c1!=0  && c2==0){
//             if(s2<=s1) return -1;
//             else{
//                 if(c1>(s2-s1)) return -1;
//                 else return s2;
//             }
//         }
//         else{
//             return max(s1+c1, s2+c2);
//         }
//         return -1;
        
        // Way-2: 
//          long long s1=0, s2=0, c1=0, c2=0;
//         for(int i=0; i<nums1.size(); i++){
//             s1+= nums1[i];
//             if(nums1[i]==0) c1++;
//         }
//          for(int i=0; i<nums2.size(); i++){
//             s2+= nums2[i];
//             if(nums2[i]==0) c2++;
//         }
        
//         if((c1==0 && c2>(s1-s2)) || (c2==0 && c1>s1-s2)){
//             return -1;
//         }
//         return max(s1+c1, s2+c2);
        
         long long sum_one = 0, sum_two = 0;
        int zero_one = 0, zero_two = 0;
        for (int num : nums1)
        {
            sum_one += num;
            zero_one += (num == 0);
        }
        for (int num : nums2)
        {
            sum_two += num;
            zero_two += (num == 0);
        }
        if ((zero_one == 0 && sum_one < sum_two + zero_two) || (zero_two == 0 && sum_two < sum_one + zero_one))
            return -1;
        return max(sum_one + zero_one, sum_two + zero_two);
    }
};


