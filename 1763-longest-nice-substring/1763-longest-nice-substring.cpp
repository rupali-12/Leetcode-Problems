class Solution {
public:
    bool isNice(const string& s) {
    unordered_set<char> charSet(s.begin(), s.end());
    
    for (char c : s) {
        if (charSet.count(tolower(c)) == 0 || charSet.count(toupper(c)) == 0) {
            return false;
        }
    }
    
    return true;
}
    string longestNiceSubstring(string s) {
         if (s.length() < 2) return "";
    
    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (s.find(toupper(c)) == string::npos || s.find(tolower(c)) == string::npos) {
            // Split around character that breaks the nice condition
            string left = longestNiceSubstring(s.substr(0, i));
            string right = longestNiceSubstring(s.substr(i + 1));
            // Return the longer of the two nice substrings
            return left.length() >= right.length() ? left : right;
        }
    }
    
    // If we never find a character that breaks the condition, the whole string is nice
    return s;
    }
};