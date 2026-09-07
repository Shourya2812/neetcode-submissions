class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;

        string current = "";
        int num = 0;

        for (char c : s) {

            // Build the number
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            // Start a new nested string
            else if (c == '[') {
                nums.push(num);
                strs.push(current);

                num = 0;
                current = "";
            }

            // Finish the current nested string
            else if (c == ']') {
                int k = nums.top();
                nums.pop();

                string previous = strs.top();
                strs.pop();

                string temp = "";

                for (int i = 0; i < k; i++) {
                    temp += current;
                }

                current = previous + temp;
            }

            // Normal character
            else {
                current += c;
            }
        }

        return current;
    }
};