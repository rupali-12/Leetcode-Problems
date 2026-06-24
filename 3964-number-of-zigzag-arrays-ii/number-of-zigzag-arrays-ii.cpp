class Solution {
public:
    static constexpr long long M = 1e9 + 7;

    vector<vector<long long>> mul(
        vector<vector<long long>>& A,
        vector<vector<long long>>& B
    ) {
        int m = A.size();

        vector<vector<long long>> C(
            m, vector<long long>(m, 0)
        );

        for(int i = 0; i < m; i++) {
            for(int k = 0; k < m; k++) {
                if(A[i][k] == 0) continue;

                for(int j = 0; j < m; j++) {
                    C[i][j] = (
                        C[i][j] +
                        A[i][k] * B[k][j]
                    ) % M;
                }
            }
        }

        return C;
    }

    vector<vector<long long>> matPow(
        vector<vector<long long>> base,
        int e,
        int m
    ) {
        // Identity matrix
        vector<vector<long long>> res(
            m, vector<long long>(m, 0)
        );

        for(int i = 0; i < m; i++) {
            res[i][i] = 1;
        }

        while(e > 0) {
            if(e & 1)
                res = mul(res, base);

            base = mul(base, base);
            e >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;

        vector<vector<long long>> T(
            m, vector<long long>(m,0)
        );

        for(int j = 0; j < m; j++) {
            for(int i = m-j; i < m; i++) {
                T[i][j] = 1;
            }
        }

        auto powT = matPow(T, n-1, m);

        long long total = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                total = (total + powT[i][j]) % M;
            }
        }

        return (total * 2) % M;
    }
};