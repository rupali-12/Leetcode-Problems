class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumNOdd = 2*n;
        int sumNEven = 3*n;
        return __gcd(sumNOdd, sumNEven);
    }
};

// n/2(2*1+(2-1)*2  = n/2(2+2) = 2n - odd

// n/2(2*2+2) =6*n/2=3n - even