class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int student1=0, student0=0;
        int n= sandwiches.size();
        for(int i=0; i<n; i++){
            if(students[i]==0) student0++;
            else student1++;
        }
        
        for(int i=0; i<n; i++){
            if(sandwiches[i]==1 && student1>0){
                student1--;
            }
            else if(sandwiches[i]==0 && student0>0){
                student0--;
            }
            else{
                return n-i;
            }
        }
        return 0;
    }
};