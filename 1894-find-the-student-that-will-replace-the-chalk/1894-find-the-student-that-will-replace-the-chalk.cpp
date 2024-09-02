class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total=0;
        for(int i=0; i<chalk.size(); i++) total+= chalk[i];
        int rem = k%total;
        
        for(int i=0; i<chalk.size(); i++){
            if(chalk[i]>rem) return i;
            
            rem-= chalk[i];
        }
        return 0;
    }
};