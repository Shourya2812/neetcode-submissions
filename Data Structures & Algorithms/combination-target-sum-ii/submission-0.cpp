class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(vector<int>& candidates, int start, int target) {

        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicate choices at the same level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Since sorted, no later element can work either
            if (candidates[i] > target)
                break;

            // Choose
            current.push_back(candidates[i]);

            // i + 1 because each element can be used only once
            backtrack(candidates, i + 1, target - candidates[i]);

            // Undo
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, 0, target);

        return result;
    }
};