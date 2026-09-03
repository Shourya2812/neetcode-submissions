class Solution {
public:
    int total = 0;

    void backtrack(vector<int>& nums, int i, int xorValue) {
        // All elements processed
        if (i == nums.size()) {
            total += xorValue;
            return;
        }

        // Include nums[i]
        backtrack(nums, i + 1, xorValue ^ nums[i]);

        // Don't include nums[i]
        backtrack(nums, i + 1, xorValue);
    }

    int subsetXORSum(vector<int>& nums) {
        backtrack(nums, 0, 0);
        return total;
    }
};
