class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int left = *max_element(weights.begin(), weights.end());

        int right = accumulate(
            weights.begin(),
            weights.end(),
            0
        );

        while (left < right) {

            int mid = left + (right - left) / 2;

            int requiredDays = 1;
            int currentLoad = 0;

            for (int weight : weights) {

                if (currentLoad + weight > mid) {
                    requiredDays++;
                    currentLoad = 0;
                }

                currentLoad += weight;
            }

            if (requiredDays <= days) {
                // Capacity works.
                // Try smaller capacity.
                right = mid;
            }
            else {
                // Capacity is too small.
                left = mid + 1;
            }
        }

        return left;
    }
};