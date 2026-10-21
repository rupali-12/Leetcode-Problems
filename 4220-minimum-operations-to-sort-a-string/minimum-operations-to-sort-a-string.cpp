class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        
        // case-1 already sorted
        if(is_sorted(s.begin(), s.end())) return 0;

        // case-2 two char are present only
        if(n==2) return -1;

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // if only one operation is enough
        if(mn==s[0] || mx==s[n-1]) return 1;

        // if max or min is in middle
        for(int i=1; i<n-1; i++){
            if(s[i]==mn || s[i]==mx) return 2;
        }

        // if neither case
        return 3;
    }
};