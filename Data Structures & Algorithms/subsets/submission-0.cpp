class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(vector<int>& nums, int i) {
        if (i == nums.size()) {
            result.push_back(current);
            return;
        }

        // Take nums[i]
        current.push_back(nums[i]);
        backtrack(nums, i + 1);

        // Undo
        current.pop_back();

        // Don't take nums[i]
        backtrack(nums, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }
};