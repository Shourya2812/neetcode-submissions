class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used;

    void backtrack(vector<int>& nums) {

        // Complete permutation
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            // Already used
            if (used[i])
                continue;

            // Choose
            current.push_back(nums[i]);
            used[i] = true;

            // Explore
            backtrack(nums);

            // Undo
            used[i] = false;
            current.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(), false);

        backtrack(nums);

        return result;
    }
};