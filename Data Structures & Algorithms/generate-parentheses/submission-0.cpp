class Solution {
public:
    vector<string> result;

    void backtrack(string current, int open, int close, int n) {

        // Complete valid string
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add '('
        if (open < n) {
            current.push_back('(');
            backtrack(current, open + 1, close, n);
            current.pop_back();
        }

        // Add ')'
        if (close < open) {
            current.push_back(')');
            backtrack(current, open, close + 1, n);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return result;
    }
};