class Solution {
public:

    void reverseArray(vector<int>& nums, int left, int right) {

        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        k = k % n;

        // Reverse entire array
        reverseArray(nums, 0, n - 1);

        // Reverse first k elements
        reverseArray(nums, 0, k - 1);

        // Reverse remaining elements
        reverseArray(nums, k, n - 1);
    }
};