class Solution {
public:
    vector<vector<string>> result;
    vector<string> current;

    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    void backtrack(string& s, int start) {

        // Reached the end
        if (start == s.size()) {
            result.push_back(current);
            return;
        }

        // Try every possible substring
        for (int end = start; end < s.size(); end++) {

            // Only choose palindrome substrings
            if (!isPalindrome(s, start, end))
                continue;

            // Choose
            current.push_back(s.substr(start, end - start + 1));

            // Explore remaining string
            backtrack(s, end + 1);

            // Undo
            current.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return result;
    }
};