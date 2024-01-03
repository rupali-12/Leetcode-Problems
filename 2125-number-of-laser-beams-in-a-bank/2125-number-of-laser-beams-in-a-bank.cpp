class Solution {
public:
//     int solve(vector<string>& bank, int i, int j, int m, int n){
//         int x=i, y=j;
//         int ans=0;
        
//         // down 
//         while(x<m){
//             if(bank[x][y]=='1'){
//                 ans++;
//             }
//             x++;
//         }
        
//          // left lower diagonal
//         while(x<m && y>=0){
//             if(bank[x][y]=='1'){
//                 ans++;
//             }
//             x++; y--;
//         }
        
//          // right lower diagonal 
//         while(x<m && y<n){
//             if(bank[x][y]=='1'){
//                 ans++;
//             }
//             x++; y++;
//         }
//         return ans;
//     }
    int numberOfBeams(vector<string>& bank) {
        // approach-1: not work 
        // int ans=0;
        // int m = bank.size(), n= bank[0].size();
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(bank[i][j]=='1'){
        //             ans+= solve(bank, i, j, m, n);
        //             cout<<ans<<" "<<i<<" "<<j<<endl;
        //         }
        //     }
        // }
        // return ans;
        
        // approach-2: 
        int ans=0;
        int m = bank.size(), n= bank[0].size();
        vector<int>v;
        for(int i=0; i<m; i++){
            string s= bank[i];
            int temp=0;
            for(auto a: s){
                if(a=='1'){
                temp++;
                }
            }
           if(temp!=0){
                v.push_back(temp);
           }
        }
        
        for(int i=1; i<v.size(); i++){
            int t = v[i]*v[i-1];
            ans+= t;
        }
        return ans;
    }
};