class Solution {
public:
    int splitArray(vector<int>& nums, int k) {

        long long left = *max_element(nums.begin(), nums.end());

        long long right = accumulate(
            nums.begin(),
            nums.end(),
            0LL
        );

        while (left < right) {

            long long mid = left + (right - left) / 2;

            // Check how many subarrays are needed
            // if maximum allowed sum = mid
            int subarrays = 1;
            long long currentSum = 0;

            for (int num : nums) {

                if (currentSum + num > mid) {
                    subarrays++;
                    currentSum = 0;
                }

                currentSum += num;
            }

            // mid is possible
            if (subarrays <= k) {
                right = mid;
            }
            else {
                // mid is too small
                left = mid + 1;
            }
        }

        return left;
    }
};