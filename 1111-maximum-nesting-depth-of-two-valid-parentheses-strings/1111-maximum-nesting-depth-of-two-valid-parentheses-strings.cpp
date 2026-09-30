class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {

        vector<int> ans;

        int depth = 0;

        for(char ch : seq) {

            if(ch == '(') {
                depth++;

                // Current nesting level
                ans.push_back(depth % 2);
            }
            else {
                // Closing bracket belongs to current level
                ans.push_back(depth % 2);

                depth--;
            }
        }

        return ans;
    }
};