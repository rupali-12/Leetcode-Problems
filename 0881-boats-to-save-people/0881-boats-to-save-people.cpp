class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int numBoats=0, i=0, j= people.size()-1;
        sort(people.begin(), people.end());

        while(i<=j){
            if((people[i]+people[j])<=limit){
                i++;
                j--;
                numBoats++;
            }
            else{
                numBoats++;
                j--;
            }
        }
        return numBoats;
    }
};