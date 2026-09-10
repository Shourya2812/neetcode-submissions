class Solution {
public:
    int numDecodings(string s) {

        int n = s.length();

        if (s[0] == '0')
            return 0;

        int prev2 = 1;  // dp[i-2]
        int prev1 = 1;  // dp[i-1]

        for (int i = 2; i <= n; i++) {

            int curr = 0;

            // One digit
            if (s[i - 1] >= '1' && s[i - 1] <= '9') {
                curr += prev1;
            }

            // Two digits
            int num = (s[i - 2] - '0') * 10
                    + (s[i - 1] - '0');

            if (num >= 10 && num <= 26) {
                curr += prev2;
            }

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};