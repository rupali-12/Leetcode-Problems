class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
       double total_waiting=customers[0][1];
       double t = customers[0][0] + customers[0][1];
       double n=  customers.size();
       for(int i=1; i<n; i++){
           if(t>=customers[i][0]){
                   t+= customers[i][1];
            total_waiting+= t- customers[i][0];
           }
           else{
               t= customers[i][0] +customers[i][1];
               total_waiting+= customers[i][1];
           }
           cout<<total_waiting<<" "<<endl;
       }
    double ans =  total_waiting/n;
        return ans;
    }
};