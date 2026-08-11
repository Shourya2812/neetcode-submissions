class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> m;

        int x = nums.size();

        for (int i = 0; i < x; i++) {
            m[nums[i]]++;
            if (m[nums[i]] > 1) {
                return true;
            }
        }

        return false;
    }
};