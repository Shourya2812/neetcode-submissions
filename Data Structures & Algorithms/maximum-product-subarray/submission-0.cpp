class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int currMax = nums[0];
        int currMin = nums[0];

        int answer = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            int x = nums[i];

            int newMax = max({
                x,
                x * currMax,
                x * currMin
            });

            int newMin = min({
                x,
                x * currMax,
                x * currMin
            });

            currMax = newMax;
            currMin = newMin;

            answer = max(answer, currMax);
        }

        return answer;
    }
};