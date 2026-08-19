class Solution {
public:
    bool canSit(unordered_set<int>&seats, int a, int b, int c, int d){
        return !seats.count(a) && !seats.count(b) && !seats.count(c) && !seats.count(d);
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>>usedRows;
        int ans=0;
        for(auto pos: reservedSeats){
           int row = pos[0];
           int seat = pos[1];
           usedRows[row].insert(seat);
        }

        int unusedRows = n - usedRows.size();
        ans += unusedRows*2;
       for(auto &[row, seats]: usedRows){
        bool left = canSit(seats, 2, 3, 4, 5);
        bool middle = canSit(seats, 4, 5, 6, 7);
        bool right = canSit(seats, 6, 7, 8, 9);
        if(left && right){
            ans+= 2;
        }
        else if(left || middle || right){
            ans+=1;
        }
       }
       return ans;
    }
};