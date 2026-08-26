class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;

public:

    TimeMap() {
    }

    void set(string key, string value, int timestamp) {

        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {

        if (!mp.count(key)) {
            return "";
        }

        vector<pair<int, string>>& arr = mp[key];

        int left = 0;
        int right = arr.size() - 1;

        string ans = "";

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (arr[mid].first <= timestamp) {

                // Valid timestamp
                ans = arr[mid].second;

                // Try to find a later valid timestamp
                left = mid + 1;
            }
            else {

                // Timestamp is too large
                right = mid - 1;
            }
        }

        return ans;
    }
};