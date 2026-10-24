class Solution {
public:
    int daysOfYear(string str){
        vector<int>days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(str.substr(0, 2));
        int day = stoi(str.substr(3, 2));

        for(int i=0; i<month-1; i++){
            day+= days[i];
        }
        return day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aStart = daysOfYear(arriveAlice);
        int aEnd = daysOfYear(leaveAlice);
        int bStart = daysOfYear(arriveBob);
        int bEnd = daysOfYear(leaveBob);

        int start = max(aStart, bStart);
        int end = min(aEnd, bEnd);
        return max(0, end-start+1); 
    }
};