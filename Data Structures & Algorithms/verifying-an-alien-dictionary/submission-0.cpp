class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        // Store the rank of each character
        vector<int> rank(26);

        for (int i = 0; i < 26; i++) {
            rank[order[i] - 'a'] = i;
        }

        // Compare every adjacent pair of words
        for (int i = 0; i < words.size() - 1; i++) {

            string w1 = words[i];
            string w2 = words[i + 1];

            int j = 0;

            // Compare until first different character
            while (j < w1.size() && j < w2.size()) {

                if (w1[j] != w2[j]) {

                    // If w1's character comes after w2's
                    if (rank[w1[j] - 'a'] > rank[w2[j] - 'a'])
                        return false;

                    // First different character decides the order
                    break;
                }

                j++;
            }

            // Prefix case
            // Example: ["apple", "app"] -> false
            if (j == w2.size() && j < w1.size())
                return false;
        }

        return true;
    }
};