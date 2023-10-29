class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // trial 
        int t = minutesToTest/minutesToDie;
        int i=0;
        while(pow(t+1, i)<buckets){
            i++;
        }
        return i;
    }
};