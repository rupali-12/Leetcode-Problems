class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;
    vector<vector<int>> dp;
    bool solve(vector<vector<char>>& board, int i, int j, string word,
               int index) {
        if (index == word.length())
            return true;
        if (i >= m || j >= n || i < 0 || j < 0)
            return false;
        bool ans = false;
        if (word[index] == board[i][j]) {
            board[i][j] = '*'; // mark for visit
            bool right = solve(board, i, j + 1, word, index+1);
            bool left = solve(board, i, j - 1, word, index+1);
            bool up = solve(board, i - 1, j, word, index+1);
            bool down = solve(board, i + 1, j, word, index+1);
            ans = right || left || up || down;

            // backtrack
            board[i][j] = word[index];
        }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        int index = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word[index] == board[i][j]) {
                    if (solve(board, i, j, word, index))
                        return true;
                }
            }
        }
        return false;
    }
};