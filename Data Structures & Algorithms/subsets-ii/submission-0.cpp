class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(vector<int>& nums, int start) {

        // Every current subset is a valid answer
        result.push_back(current);

        for (int i = start; i < nums.size(); i++) {

            // Skip duplicate choices at the same level
            if (i > start && nums[i] == nums[i - 1])
                continue;

            // Choose
            current.push_back(nums[i]);

            // Move forward because each index can be used once
            backtrack(nums, i + 1);

            // Undo
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        backtrack(nums, 0);

        return result;
    }
};