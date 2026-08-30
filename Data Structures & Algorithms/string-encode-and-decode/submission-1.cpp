class Solution {
public:

    // Encode vector<string> into one string
    string encode(vector<string>& strs) {

        string result = "";

        for (string& str : strs) {

            // Store length + delimiter + string
            result += to_string(str.size()) + "#" + str;
        }

        return result;
    }

    // Decode one string back into vector<string>
    vector<string> decode(string s) {

        vector<string> result;

        int i = 0;

        while (i < s.size()) {

            // Find the '#'
            int j = i;

            while (s[j] != '#') {
                j++;
            }

            // Convert length part to integer
            int len = stoi(s.substr(i, j - i));

            // Move past '#'
            j++;

            // Extract exactly len characters
            string str = s.substr(j, len);

            result.push_back(str);

            // Move to the beginning of next encoded string
            i = j + len;
        }

        return result;
    }
};