class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int index) {

        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for (int i = index; i < nums.size(); i++) {

            // Same value already used at this level
            if (used.count(nums[i]))
                continue;

            used.insert(nums[i]);

            // Choose
            swap(nums[index], nums[i]);

            // Explore
            backtrack(nums, index + 1);

            // Undo
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }
};