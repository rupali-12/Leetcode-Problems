class Solution {
public:
    int numberOfChild(int n, int k) {
        if (k == 1)
            return 1;
        
        int curr = 1;
        bool dir = false;
        k--;
        while (k--)
        {
            if (curr == n - 1)
                dir = true;
            if (curr == 0)
                dir = false;
            
            if (dir == false)
                curr++;
            if (dir == true)
                curr--;
            
        }
        
        return curr;
    }
};