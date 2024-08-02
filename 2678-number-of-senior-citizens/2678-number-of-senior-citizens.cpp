class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(int i=0; i<details.size(); i++){
            string age= details[i].substr(11, 2);
            int ageNum= stoi(age);
            if(ageNum>60) count++;
        }
        return count;
    }
};