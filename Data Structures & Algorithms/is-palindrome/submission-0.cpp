class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {

            // Skip non-alphanumeric characters from left
            while (i < j && !isalnum(s[i])) {
                i++;
            }

            // Skip non-alphanumeric characters from right
            while (i < j && !isalnum(s[j])) {
                j--;
            }

            // Compare characters ignoring case
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};