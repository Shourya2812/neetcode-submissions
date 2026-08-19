class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<vector<int>, vector<string>> mp;

        for (string s : strs) {

            vector<int> count(26, 0);

            for (char c : s) {
                count[c - 'a']++;
            }

            mp[count].push_back(s);
        }

        vector<vector<string>> ans;

        for (auto& pair : mp) {
            ans.push_back(pair.second);
        }

        return ans;
    }
};