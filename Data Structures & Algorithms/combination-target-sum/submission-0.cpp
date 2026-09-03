class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(vector<int>& candidates, int start, int target) {
        // Found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // No point continuing
            if (candidates[i] > target)
                continue;

            // Choose
            current.push_back(candidates[i]);

            // i, NOT i + 1, because we can reuse the same number
            backtrack(candidates, i, target - candidates[i]);

            // Undo
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, 0, target);
        return result;
    }
};