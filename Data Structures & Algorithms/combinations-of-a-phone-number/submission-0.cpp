class Solution {
public:
    vector<string> letters = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> res;
    string current;

    void backtrack(int i, string& digits) {

        if (i == digits.size()) {
            res.push_back(current);
            return;
        }

        for (char c : letters[digits[i] - '0']) {

            current.push_back(c);

            backtrack(i + 1, digits);

            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        backtrack(0, digits);

        return res;
    }
};