class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
//         // Approach-1>> Using deque
//         deque<int>dq;
//         for(auto a: students){
//             dq.push_back(a);
//         }
        
//         for(auto a: sandwiches){
//             if(dq.front()==a){
//                 dq.pop_front();
//             }
//             int s=dq.size();
//             int f=0;
//             while(s--){
//                 int x=dq.front();
//                 if(x==a){
//                     dq.pop_front();
//                     f=1;
//                     break;
//                 }
//                 else{
//                dq.pop_front();
//                dq.push_back(x);
//                 }
//             }
//             if(f==0){
//                 return dq.size();
//             }
        // }
        // return 0;
        
        // Approach-2>> 
        vector<int>v(2);
        for(auto a: students){
            v[a]++;
        }
        
        for(auto a:sandwiches){
             if(v[a]>0){
                 v[a]--;
             }
            else{
                return v[1]+v[0];
            }
        }
        return 0;
    }
};